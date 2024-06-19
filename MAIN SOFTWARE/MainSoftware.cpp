#include "MainSoftware.hpp"



/*
*==========================================================================================*
*  argv[0] = Backend_Testing_CPP.exe                                                       *
*                                                                                          *
*  if:         argv[1] == "username" (VALIDATE_USERNAME_STR)	(VALIDATE_USERNAME) [ ON ]  *
*  else if:    argv[1] == "password" (VALIDATE_PASSWORD_STR)	(VALIDATE_PASSWORD) [ ON ]  *
*  else:       [EXIT_FAILURE] Error input param (argv[1])                                  *
*                                                                                          *
*  argv[2] = "The value under test"                                                        *
*==========================================================================================*
*/



int main(int argc, char *argv[])
{
#if defined(_WIN32) || defined(_WIN64)
   if (argc != 3)
   {
      std::cout << "Error input param (argc)\nExpected:  1 == VALIDATE_USERNAME\n/*OR*/\nnExpected: 2 == VALIDATE_PASSWORD\n[Code] - [" << EXIT_FAILURE << "]" << std::endl;
      return EXIT_FAILURE;
   }

   if (std::string(argv[1]) == VALIDATE_USERNAME_STR)
   {
      std::string username(argv[2]);
      std::cout << TestManager::IsValidUsername(username) << std::endl;
   }
   else if (std::string(argv[1]) == VALIDATE_PASSWORD_STR)
   {
      std::string password(argv[2]);
      std::cout << TestManager::IsValidPassword(password) << std::endl;
   }
   else
   {
      std::cout << "Error input param (argv[1])\nExpected:  1 == VALIDATE_USERNAME\n/*OR*/\nnExpected: 2 == VALIDATE_PASSWORD\n[Code][" << EXIT_FAILURE << "]" << std::endl;
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
   if (argc != 3)
   {
      std::cout << "Error input param (argc[1])\nExpected:  1 == VALIDATE_USERNAME\n/*OR*/\nnExpected: 2 == VALIDATE_PASSWORD\n[Code][" << "-1009" << "]" << std::endl;
      return -1009;
   }

   if (std::string(argv[1]) == VALIDATE_USERNAME_STR)
   {
      std::string username(argv[2]);
      TestManager::IsValidUsername(username);
   }
   else if (std::string(argv[1]) == VALIDATE_PASSWORD_STR)
   {
      std::string password(argv[2]);
      TestManager::IsValidPassword(password);
   }
   else
   {
      std::cout << "Error input param (argv[1])\nExpected:  1 == VALIDATE_USERNAME\n/*OR*/\nnExpected: 2 == VALIDATE_PASSWORD\n[Code][" << "-1009" << "]" << std::endl;
      return -1009;
   }

   return 0;
#else
   std::cout << "Unsupported platform for this microservice [-901]" << std::endl;
   return -901;
#endif
}