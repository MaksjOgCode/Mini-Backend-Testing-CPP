using System;
using System.Diagnostics;
using System.IO;
using TestApp;
using static System.Console;

namespace TestApp
{
    public class BackendTester
    {
        private readonly string _exePath;

        public BackendTester(string exePath)
        {
            if (!File.Exists(exePath) || Path.GetExtension(exePath) != ".exe")
                throw new ArgumentException("Invalid executable file path", nameof(exePath));

            _exePath = exePath;
        }

        public string ExecuteTest(string arguments)
        {
            if (string.IsNullOrWhiteSpace(arguments))
                throw new ArgumentException("Arguments cannot be null or whitespace", nameof(arguments));

            using var process = new Process
            {
                StartInfo = new ProcessStartInfo
                {
                    FileName = _exePath,
                    Arguments = arguments,
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    CreateNoWindow = true
                }
            };

            process.Start();

            string output = process.StandardOutput.ReadToEnd();
            process.WaitForExit();

            if (process.ExitCode != 0)
                throw new InvalidOperationException($"Process exited with code {process.ExitCode}");

            return output;
        }
    }
}

namespace Test_Connect
{
    class Program
    {
                        /* Add your path to .exe program: */
        const string ExePath = @"Disk:\path\to\program\Backend_Testing_CPP.exe";

        static void Main(string[] args)
        {
            var tester = new BackendTester(ExePath);

            try
            {               /* Change the mode for testing: */
                var result = tester.ExecuteTest("username Some_Kind_Of_Username");

                WriteLine(result);
            }
            catch (Exception ex)
            {
                WriteLine($"Error: {ex.Message}");
            }
        }
    }
}