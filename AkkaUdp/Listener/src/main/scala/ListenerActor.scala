import java.net.InetSocketAddress

import akka.actor.{Actor, ActorLogging, ActorRef, Props}
import akka.io.{IO, Udp}
import akka.util.ByteString

class ListenerActor(local: InetSocketAddress, remote: InetSocketAddress) extends Actor with ActorLogging {

  import context.system
  IO(Udp) ! Udp.Bind(self, local)

  def receive = {
    case Udp.Bound(_) ⇒
      context.become(ready(sender()))
  }

  def ready(send: ActorRef): Receive = {
    case msg: String ⇒
      send ! Udp.Send(ByteString(msg), remote)

    case Udp.Received(data, remoteAddress) ⇒
      val ipAddress = remoteAddress.getAddress.getHostAddress
      val port = remoteAddress.asInstanceOf[InetSocketAddress].getPort
      log.info(s"we received ${data.utf8String} from IP Address: $ipAddress and port number: $port")
      send ! Udp.Send(ByteString("Hello back"), remote)
  }
}

object ListenerActor {
  def apply(local: InetSocketAddress, remote: InetSocketAddress) = Props(classOf[ListenerActor], local, remote)
}