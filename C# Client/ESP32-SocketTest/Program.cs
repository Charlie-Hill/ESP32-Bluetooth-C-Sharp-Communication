using System;
using System.IO.Ports;
using System.IO;
using System.Threading;

namespace ESP32_SocketTest
{
    class MainClass
    {

        public static void Main(string[] args)
        {
            SerialPort serialPort = new SerialPort();
            bool connected = false;

            SerialPort tmp;
            foreach (string str in SerialPort.GetPortNames())
            {
                tmp = new SerialPort(str);
                if (tmp.IsOpen == false)
                {

                    serialPort.PortName = str;

                    try
                    {
                        //open serial port
                        serialPort.Open();
                        serialPort.BaudRate = 9600;
                        serialPort.WriteTimeout = 3000;
                        serialPort.ReadTimeout = 3000;
                        serialPort.Write("<mccon>");
                        String s = serialPort.ReadTo("\n");
                        if (s.Contains("<connected>"))
                        {
                            connected = true;
                            break;
                        }
                        else
                        {
                            serialPort.Close();
                        }
                    }
                    catch (TimeoutException)
                    {
                        serialPort.Close();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine("ERROR: {0}", ex.Message);
                    }
                }
            }


            if (connected)
            {
                try
                {
                    Console.Write("Enter what you want to send: ");
                    string response = Console.ReadLine();
                    serialPort.Write(response);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Encountered error while writing to / or reading from serial port");
                    Console.WriteLine(ex.ToString());
                }
            }
            else
            {
                Console.WriteLine("Not Found");
            }
        }
    }
}