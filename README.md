# Mini-Backend-Testing-CPP
Mini-Backend-Testing-CPP is a console application written in C++ that provides a set of functions for checking the correctness of input data, such as logins and passwords. The program uses the C++ Standard Library (STL) and can be launched from the command line or run within your program's source code.
*===========================================================================*
## MainSoftware.hpp
The MainSoftware.hpp file contains the definition of the TestManager class, which provides a set of functions for checking the correctness of input data such as usernames and passwords. In particular, the class contains the following methods:
* IsValidUsername(): checks if a string is a valid username;
* IsValidPassword(): checks if a string is a valid password;
* IsValidAccount(): checks if a username and password are valid;
* IsValidUsernameEx(): an extended version of the IsValidUsername() function that returns a vector of "description-value" pairs containing detailed information about the verification results;
* IsValidPasswordEx(): an extended version of the IsValidPassword() function that returns a vector of "description-value" pairs containing detailed information about the verification results;
* IsValidAccount(): checks if a username and password are valid using the extended versions of the IsValidUsernameEx() and IsValidPasswordEx() functions.

In addition, the class contains private methods:
* CheckForbiddenChars();
* CheckUppercase();
* CheckLowercase();
* CheckLength().
These private methods are used to check specific aspects of the input data, such as the presence of forbidden characters, letter case, and string length.

The file also contains the definitions of the following macros:
* VALIDATE_USERNAME_STR;
* VALIDATE_PASSWORD_STR.
These macros are used to indicate the types of checks performed by the IsValidUsername() and IsValidPassword() functions.

Also, if the _WIN32 or _WIN64 macro is defined, the file includes the <Windows.h> header file.
*===========================================================================*
## MainSoftware.cpp
This is a CPP file that includes the "MainSoftware.hpp" header file. The main function takes two arguments, argc and argv, which are used to handle command line arguments. The program expects three arguments, the first one being the program name, the second one being either "username" or "password" to indicate whether to validate a username or a password, and the third one being the value to be tested.

The program first checks if the correct number of arguments have been provided. If not, it prints an error message and returns an error code. Then it checks if the second argument is either "username" or "password". If it is "username", it calls the IsValidUsername function from the TestManager class with the third argument as the username to be tested. If it is "password", it calls the IsValidPassword function from the TestManager class with the third argument as the password to be tested. If the second argument is neither "username" nor "password", it prints an error message and returns an error code.

The program uses preprocessor directives to check the operating system and compiles accordingly. If the operating system is Windows, it returns EXIT_SUCCESS or EXIT_FAILURE. If the operating system is Linux, Unix, or Apple, it returns 0 or -1009. If the operating system is not supported, it prints an error message and returns -901.
*===========================================================================*
# A short guide
argv[0] = Backend_Testing_CPP.exe

if:         argv[1] == "username" (VALIDATE_USERNAME_STR)	(VALIDATE_USERNAME) [ ON ]
else if:    argv[1] == "password" (VALIDATE_PASSWORD_STR)	(VALIDATE_PASSWORD) [ ON ]
else:       [EXIT_FAILURE] Error input param (argv[1])
                                                                                          
argv[2] = "The value under test"
*===========================================================================*
# The program can be run simply from the command line:
```
cd Disk:\path\to\program
```
```
Backend_Testing_CPP.exe username Example_User
```
Here:
* argv[0] = Backend_Testing_CPP.exe
* argv[1] = username
* argv[2] = Example_User

*===========================================================================*
## Here is an example of using the code written in C#:
```
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
```
