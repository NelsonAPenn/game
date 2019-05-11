import java.applet.*
import java.awt.*
import javax.swing.JButton
import javax.swing.JFrame
import javax.swing.JPanel



class Main
{
    companion object {
        @JvmStatic fun main(args: Array<String>)
        {
            val frame = JFrame("JFrame")
            frame.defaultCloseOperation = JFrame.EXIT_ON_CLOSE

            System.out.println("Please run")


            frame.pack()
            frame.isVisible = true
        }

    }
}
