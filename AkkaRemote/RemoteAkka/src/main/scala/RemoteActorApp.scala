import akka.actor._

object RemoteActorApp extends App  {
  val system = ActorSystem("RemoteActorSystem")
  val remoteActor = system.actorOf(Props[RemoteActor], name = "RemoteActor")
}