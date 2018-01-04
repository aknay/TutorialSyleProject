package controllers

import javax.inject._

import play.api.libs.json.Json
import play.api.mvc._
import play.api.routing.JavaScriptReverseRouter
import services.NameStorage

import scala.concurrent.Future

@Singleton
class HomeController @Inject()(cc: ControllerComponents) extends AbstractController(cc) {

  def index = Action {
    Ok(views.html.index("Ajax Play Application"))
  }

  def getName = Action.async { implicit request =>
    Future.successful(Ok(Json.toJson(NameStorage.getName)))
  }

  def updateName(name: String) = Action.async { implicit request =>
    NameStorage.setName(name)
    Future.successful(Ok(Json.toJson(NameStorage.getName)))
  }

  def jsRoutes = Action { implicit request =>
    Ok(
      JavaScriptReverseRouter("jsRoutes")(
        routes.javascript.HomeController.getName,
        routes.javascript.HomeController.updateName
      )).as("text/javascript")
  }

}