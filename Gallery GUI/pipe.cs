using System;
using System.IO.Pipes;
using System.IO;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace Gallery_GUI
{
    public class PipeServer
    {
        NamedPipeServerStream pipeServer;
        StreamString ss;

        public PipeServer()
        {
            pipeServer = new NamedPipeServerStream("galleryPIPE", PipeDirection.InOut, 1);
            ss = new StreamString(pipeServer);
        }

        public bool Connect()
        {
            Console.WriteLine("Waiting for connection...");
            pipeServer.WaitForConnection();
            return pipeServer.IsConnected;
        }

        public bool IsConnected()
        {
            return pipeServer.IsConnected;
        }

        public string SendMessageToClient(string message)
        {
            if (IsConnected())
            {
                byte[] buffer = Encoding.ASCII.GetBytes(message);
                pipeServer.Write(buffer, 0, buffer.Length);
                pipeServer.Flush(); 
                Console.WriteLine("Message sent to C++ client: " + message);

                byte[] responseBuffer = new byte[1024]; 
                int bytesRead = pipeServer.Read(responseBuffer, 0, responseBuffer.Length); 

                if (bytesRead > 0)
                {
                    string response = Encoding.ASCII.GetString(responseBuffer, 0, bytesRead).TrimEnd('\0');
                    Console.WriteLine("Response received from C++ client: " + response);
                    return response;
                }
                else
                {
                    Console.WriteLine("No response received from C++ client.");
                    return "";
                }
            }
            else
            {
                Console.WriteLine("Not connected to the client.");
                return "";
            }
        }


        public void Close()
        {
            pipeServer.Close();
        }
    }

    public class StreamString
    {
        private Stream ioStream;
        private Encoding streamEncoding;

        public StreamString(Stream ioStream)
        {
            this.ioStream = ioStream;
            streamEncoding = new ASCIIEncoding();
        }

        public string GetStringFromEngine()
        {
            byte[] inBuffer = new byte[1024];
            ioStream.Read(inBuffer, 0, 1024);

            string myString = Encoding.ASCII.GetString(inBuffer).TrimEnd((char)0);
            return myString;
        }
    }
}