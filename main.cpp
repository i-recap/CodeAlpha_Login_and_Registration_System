#include<iostream>
#include<fstream>
#include<string>
#include<functional>
#include<filesystem>

bool set_field(std::string &field, int min_length)
{
    std::string field_name = field;
    field = "";
    int choice;
    do
    {
        std::cout << "Enter " + field_name << ": ";
        std::cin >> field;
        if(field.empty() || field.length() < min_length)
        {
            std::cout << field_name << " is either empty or too short(min length is "<< min_length << " ) " << std::endl;
            std::cout << "Do you want to re-enter " << field_name << " (1->yes): ";
            std::cin >> choice;
            if(choice != 1)
            {
                return false;
            }
            continue;
        }
        return true;
    }while(true);

    return false;
}
bool set_credentials(std::string &username, std::string &password)
{
    if(set_field(username = "Username", 3))
    {
        return set_field(password = "Password" , 6);
    }
    return false;
}

unsigned long long hash_password(std::string input_string)
{
    unsigned long long seed = 5381;
    for(char c : input_string)
    {
        seed = (seed * 33 + c);
    }
    return seed;
}

bool user_exists(std::string username)
{
    std::ifstream file("users/" + username + ".txt");
    if(file.is_open())
    {
        return true;
    }
    return false;
}

bool create_folder()
{
    std::string folder_name = "users";
    if(std::filesystem::exists(folder_name))
    {
        if(std::filesystem::is_directory(folder_name))
        {
            return true;
        }
        else
        {
            std::cout << "Some file with name \"users\" exists but not as directory" << std::endl; 
            return false;
        }
    }
    return std::filesystem::create_directory(folder_name);
}

void register_user(std::string username, std::string password)
{
    if(!user_exists(username)) 
    {
        std::ofstream file("users/" + username + ".txt");
        
        file << hash_password(username + password);
        file.close();
        std::cout << "User Registered Successfully" << std::endl;
        return;
    }
    std::cout << "User with provided username already exist!!" << std::endl;
    std::cout << "Please try with another username " << std::endl;
}

void login_user(std::string username, std::string password)
{
    std::ifstream file("users/" + username + ".txt");
    if(file.is_open())
    {
        unsigned long long stored_password; 
        file >> stored_password;
        do
        {
            if(stored_password == hash_password(username + password))
            {
                std::cout << "Login Successful" << std::endl;
                std::cout << "Welcome " << username << std::endl;
                return;
            }
            else
            {
                std::cout << "Entered password is incorrect!! " << std::endl;
                int choice = 0;
                std::cout << "Do you want to re-enter password (1->yes): ";
                std::cin >> choice;
                if(choice != 1)
                {
                    return;
                }
                else
                {
                    std::cout << "Enter Password: ";
                    std::cin >> password; 
                }
            }
        }while(true);
    }
    std::cout << "user with provided credentials doesnt exist!" << std::endl;
}

int main()
{
    if(!create_folder())
    {
        std::cout << "Directory \"users\" not found!!!" << std::endl;
        std::cout << "Please create directory \"users\" in current directory before running again" << std::endl;
        return 0;
    }

    int choice;
    std::string username, password;
    do
    {
        std::cout << "Welcome To Login and Registration System" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Register" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch(choice)
        {
            case 1:
            {
                if(set_credentials(username, password))
                {
                    login_user(username, password);
                }
                break;
            }
            case 2:
            {
                if(set_credentials(username, password))
                {
                    register_user(username, password);
                }
                break;
            }
            case 3:
            {
                std::cout << "Thank You for using the System!!!" << std::endl;
                return 0;
                break;
            }
            default:
            {
                std::cout << "Invalid choice!!! Please Retry" << std::endl;
                break; 
            }
        }
        std::cout << "Do you want to continue (1->yes): ";
        std::cin >> choice;
        if(choice != 1)
        {
            break;
        }
    }while(true);
}