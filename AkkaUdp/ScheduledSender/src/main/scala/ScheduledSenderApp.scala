import java.net.InetSocketAddress

import akka.actor._

object ScheduledSenderApp extends App {
  val system = ActorSystem("ActorSystem")
  val remote = new InetSocketAddress("localhost", 5005)
  val local = new InetSocketAddress("localhost", 5115)

  val udp: ActorRef = system.actorOf(ScheduledSenderActor(local, remote), name = "Udp")
}