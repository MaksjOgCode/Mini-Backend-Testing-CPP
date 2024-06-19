#ifndef MAINSOFTWARE_HPP
#define MAINSOFTWARE_HPP



//----------------------------------------------------------------------------------------------------
#define VALIDATE_USERNAME_STR    "username"
#define VALIDATE_PASSWORD_STR    "password"
//----------------------------------------------------------------------------------------------------
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif
//----------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//----------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------
class TestManager
{
public:
   static inline bool IsValidUsername  (const std::string &user_name);
   static inline bool IsValidPassword  (const std::string &password);
   static inline bool IsValidAccount   (const bool &is_coorect_user_name, const bool &is_correct_password);

   static inline std::vector < std::pair <std::string, bool> > IsValidUsernameEx (const std::string &user_name);
   static inline std::vector < std::pair <std::string, bool> > IsValidPasswordEx (const std::string &password);
   static inline bool	IsValidAccount (  const std::vector <std::pair <std::string, bool>> &user_name,
                                          const std::vector <std::pair <std::string, bool>> &password    );
private:
   TestManager() = delete;

   static inline bool CheckForbiddenChars (const std::string& input);
   static inline bool CheckUpperñase      (const std::string& input);
   static inline bool CheckLowercase      (const std::string& input);
   static inline bool CheckLength         (const std::string& input, const char left, const char right);
};
//----------------------------------------------------------------------------------------------------



/* PUBLIC SECTION: */
//----------------------------------------------------------------------------------------------------
std::vector <std::pair <std::string, bool>> TestManager::IsValidUsernameEx (const std::string &user_name)
{  /* Extended version of the function: IsValidUsername(const std::string &user_name): */
   std::vector <std::pair <std::string, bool> > desription = {
      {"Is Valid Username: ",				false},
      {"Validate Forbidden Chars: ",	false},
      {"Validate Uppercase: ",			false},
      {"Validate Length: ",				false}	};

   if ( user_name.empty() )
      return desription;

   desription[1].second = TestManager::CheckForbiddenChars  (user_name);
   desription[2].second = TestManager::CheckUpperñase       (user_name);
   desription[3].second = TestManager::CheckLength          (user_name, 3, 16);
   if (  desription[1].second &&
         desription[2].second &&
         desription[3].second )
   {
      desription[0].second = true;
   }

   return desription;
}
//----------------------------------------------------------------------------------------------------
std::vector <std::pair <std::string, bool>> TestManager::IsValidPasswordEx (const std::string &password)
{  /* Extended version of the function: IsValidPassword(const std::string &user_name): */
   std::vector <std::pair <std::string, bool> > desription = {
      {"Is Valid Password: ",				false},
      {"Validate Additional Chars: ",	false},
      {"Validate Uppercase: ",			false},
      {"Validate Lowercase: ",			false},
      {"Validate Length: ",				false}	};

   if ( password.empty() )
      return desription;

   desription[1].second = (  !TestManager::CheckForbiddenChars (password) );
   desription[2].second =     TestManager::CheckUpperñase      (password);
   desription[3].second =     TestManager::CheckLowercase      (password);
   desription[4].second =     TestManager::CheckLength         (password, 8, 50);
   if (  desription[1].second &&
         desription[2].second &&
         desription[3].second &&
         desription[4].second )
   {
      desription[0].second = true;
   }

   return desription;
}
//----------------------------------------------------------------------------------------------------
bool TestManager::IsValidUsername (const std::string &user_name)
{
   std::vector <std::pair <std::string, bool> > desription = {
      {"Is Valid Username: ",				false},
      {"Validate Forbidden Chars: ",	false},
      {"Validate Uppercase: ",			false},
      {"Validate Length: ",				false}	};

   if ( user_name.empty() )
      return false;

   bool result_testing = false;
   desription[1].second = TestManager::CheckForbiddenChars  (user_name);
   desription[2].second = TestManager::CheckUpperñase       (user_name);
   desription[3].second = TestManager::CheckLength          (user_name, 3, 16);
   if (  desription[1].second &&
         desription[2].second &&
         desription[3].second )
   {
      result_testing = true;
   }

   return result_testing;
}
//----------------------------------------------------------------------------------------------------
bool TestManager::IsValidPassword (const std::string &password)
{
   std::vector <std::pair <std::string, bool> > desription = {
      {"Is Valid Password: ",				false},
      {"Validate Additional Chars: ",	false},
      {"Validate Uppercase: ",			false},
      {"Validate Lowercase: ",			false},
      {"Validate Length: ",				false}	};

   if ( password.empty() )
      return false;

   bool result_testing = false;
   desription[1].second = (  !TestManager::CheckForbiddenChars (password) );
   desription[2].second =     TestManager::CheckUpperñase      (password);
   desription[3].second =     TestManager::CheckLowercase      (password);
   desription[4].second =     TestManager::CheckLength         (password, 8, 50);
   if (  desription[1].second &&
         desription[2].second &&
         desription[3].second &&
         desription[4].second )
   {
      result_testing = true;
   }

   return result_testing;
}
//----------------------------------------------------------------------------------------------------
bool TestManager::IsValidAccount (  const std::vector < std::pair <std::string, bool> > &user_name,
                                    const std::vector < std::pair <std::string, bool> > &password		)
{
   return (user_name[0].second && password[0].second);
}
//---------------------------------------------------------------------------------------------------- 
bool TestManager::IsValidAccount (const bool &is_coorect_user_name, const bool &is_correct_password)
{
   return (is_coorect_user_name && is_correct_password);
}
//----------------------------------------------------------------------------------------------------



/* PRIVATE SECTION: */
//----------------------------------------------------------------------------------------------------
bool TestManager::CheckForbiddenChars(const std::string &input)
{	/* Check for forbidden chars:	*/
   const std::string FORBIDDEN_CHARS_USERNAME = "@!#$%&'()*+,-./:;<=>?`{|}~^";
   if (input.find_first_of(FORBIDDEN_CHARS_USERNAME) == std::string::npos)
      return true;

   return false;
}
//----------------------------------------------------------------------------------------------------
bool TestManager::CheckUpperñase (const std::string& input)
{	/* Check for Upperñase:			*/
   if ( std::any_of(input.begin(), input.end(), [] (char c) {return std::isupper(c);}) )
      return true;

   return false;
}
//----------------------------------------------------------------------------------------------------
bool TestManager::CheckLowercase  (const std::string& input)
{	/* Check for Lowerñase:			*/
   if ( std::any_of(input.begin(), input.end(), [] (char c) {return std::islower(c);}) )
      return true;

   return false;
}
//----------------------------------------------------------------------------------------------------
bool TestManager::CheckLength (const std::string& input, const char left, const char right)
{	/* Check for Length string:	*/
   return input.length() >= left && input.length() <= right;
}
//----------------------------------------------------------------------------------------------------



#endif /* MAINSOFTWARE_HPP */