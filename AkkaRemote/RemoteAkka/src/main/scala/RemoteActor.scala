import akka.actor.Actor

class RemoteActor extends Actor {
  def receive = {
    case msg: String =>
      println(s"Remote Actor received message '$msg'")
      sender ! "Hello from the Remote Actor"
  }
}