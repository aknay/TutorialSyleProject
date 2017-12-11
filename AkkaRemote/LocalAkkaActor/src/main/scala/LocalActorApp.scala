import akka.actor.{ActorSystem, Props}

object LocalActorApp extends App {

  implicit val system = ActorSystem("LocalSystem")
  val localActor = system.actorOf(Props[LocalActor], name = "LocalActor")
}