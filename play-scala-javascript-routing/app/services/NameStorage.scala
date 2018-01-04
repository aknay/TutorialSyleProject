package services

object NameStorage {
  private var mName = "Bob"

  def setName(name: String): Unit = {
    mName = name
  }

  def getName: String = mName
}