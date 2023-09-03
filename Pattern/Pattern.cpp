#include<iostream>
#include<string>

class User
{
private:
	std::string name;
	std::string email;
	std::string telephoneNumber;

public:
	User(const std::string& name, const std::string& email, const std::string& phone) : name(name),email(email), telephoneNumber(phone){}

	void ShowInfo()const
	{
		std::cout << "Name: " << name << ", Email" << email << ", Telephone: " << telephoneNumber << std::endl;
	}
};

class UserFactory 
{
public:
	virtual User* CreateUser(const std::string& name, const std::string& email, const std::string& telephoneNumber) = 0;
};

class ConcreteUserFactory : public UserFactory 
{
public:
	User* CreateUser(const std::string& name, const std::string& email , const std::string& telephoneNumber) override
	{
		return new User(name, email, telephoneNumber);
	}
};

int main()
{
	ConcreteUserFactory factory;
	User* user1 = factory.CreateUser("Victor Pavlic", "VictorPavlic@gmail.com","38093665566");
	User* user2 = factory.CreateUser("Pavlo Zibrov", "GarniVusa@gmail.com", "3809366551132");

	user1->ShowInfo();
	user2->ShowInfo();

	delete user1;
	delete user2;

	return 0;
}


