import akka.actor.{Actor, ActorSelection, Cancellable}

import scala.concurrent.ExecutionContext.Implicits.global
import scala.concurrent.duration._

class LocalActor extends Actor {

  val remote: ActorSelection = context.actorSelection("akka.tcp://RemoteActorSystem@192.168.1.101:1212/user/RemoteActor")

  val TalkToRemote = "talkToRemote"

  val scheduleCancellable: Cancellable = context.system.scheduler.schedule(0.seconds, 1.second, self, TalkToRemote)

  def receive = {
    case TalkToRemote =>
      remote ! "Hello from the Local Actor"

    case msg: String =>
      println(s"LocalActor received message: '$msg'")
  }
}