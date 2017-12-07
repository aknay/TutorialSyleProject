import org.bytedeco.javacpp.opencv_core._
import org.bytedeco.javacv.FrameGrabber.ImageMode
import org.bytedeco.javacv.{CanvasFrame, Frame, OpenCVFrameGrabber}

object JavaCvExample extends App {
  val canvas = new CanvasFrame("Webcam")
  canvas.setDefaultCloseOperation(javax.swing.JFrame.EXIT_ON_CLOSE)
  val grabber = new OpenCVFrameGrabber(0)
  grabber.setBitsPerPixel(CV_8U)
  grabber.setImageMode(ImageMode.COLOR)
  grabber.start()
  val img: Frame = grabber.grab()

  canvas.showImage(img)
}