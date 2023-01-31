#include "Producents.h"




std::string md5(const std::string& str)
{
	unsigned char digest[MD5_DIGEST_LENGTH];
	MD5((unsigned char*)str.c_str(), str.length(), (unsigned char*)&digest);

	std::stringstream ss;
	for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
	}

	return ss.str();
}

void Producents::MainProducent()
{
	std::vector<Consument> consumers;
	LoadingData(consumers);
	Producent3(consumers);


}

void Producents::Producent1(std::vector<Consument>& consumer)
{
	std::string universal_password, small_password, medium_password, big_password, hash, number;
	int k = 0;

	for (int i = 0; i < dictionary.size(); i += 3)
	{
		universal_password = dictionary[i];
		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;
					c.is_broken = true;
				}
			}
		}

		universal_password[0] = toupper(universal_password[0]);
		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;

					c.is_broken = true;
				}
			}
		}

		for (int h = 0; h < universal_password.size(); h++)
		{
			universal_password[h] = toupper(universal_password[h]);
		}

		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;
					c.is_broken = true;
				}
			}
		}
	}

	while (1)
	{
		number = std::to_string(k);
		for (int i = 0; i < dictionary.size(); i += 3)
		{
			small_password = number + dictionary[i];
			medium_password = dictionary[i];
			medium_password[0] = toupper(medium_password[0]);
			medium_password = number + medium_password;
			big_password = dictionary[i];
			for (int h = 0; h < big_password.size(); h++)
			{
				big_password[h] = toupper(big_password[h]);
			}
			big_password = number + big_password;

			hash = md5(small_password);

			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << small_password << std::endl;
						c.is_broken = true;
					}
				}
			}

			hash = md5(medium_password);
			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << medium_password << std::endl;

						c.is_broken = true;
					}
				}
			}

			hash = md5(big_password);
			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << big_password << std::endl;
						c.is_broken = true;
					}
				}
			}
		}
	}


}

void Producents::Producent2(std::vector<Consument>& consumer)
{
	std::string universal_password, small_password, medium_password, big_password, hash, number;
	int k = 0;
	for (int i = 1; i < dictionary.size(); i += 3)
	{
		universal_password = dictionary[i];
		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;
					c.is_broken = true;
				}
			}
		}

		universal_password[0] = toupper(universal_password[0]);
		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;

					c.is_broken = true;
				}
			}
		}

		for (int h = 0; h < universal_password.size(); h++)
		{
			universal_password[h] = toupper(universal_password[h]);
		}

		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;
					c.is_broken = true;
				}
			}
		}
	}

	while (1)
	{
		number = std::to_string(k);
		for (int i = 0; i < dictionary.size(); i++)
		{
			small_password = dictionary[i] + number;
			medium_password = dictionary[i];
			medium_password[0] = toupper(medium_password[0]);
			medium_password =  medium_password+number;
			big_password = dictionary[i];
			for (int h = 0; h < big_password.size(); h++)
			{
				big_password[h] = toupper(big_password[h]);
			}
			big_password =  big_password+number;

			hash = md5(small_password);

			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << small_password<< std::endl;
						c.is_broken = true;
					}
				}
			}

			hash = md5(medium_password);
			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << medium_password << std::endl;

						c.is_broken = true;
					}
				}
			}

			hash = md5(big_password);
			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << big_password << std::endl;
						c.is_broken = true;
					}
				}
			}
		}
	}

}

void Producents::Producent3(std::vector<Consument>& consumer)
{
	std::string universal_password, small_password, medium_password, big_password, hash, number;
	int k = 0;
	for (int i = 2; i < dictionary.size(); i += 3)
	{
		universal_password = dictionary[i];
		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;
					c.is_broken = true;
				}
			}
		}

		universal_password[0] = toupper(universal_password[0]);
		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;

					c.is_broken = true;
				}
			}
		}

		for (int h = 0; h < universal_password.size(); h++)
		{
			universal_password[h] = toupper(universal_password[h]);
		}

		hash = md5(universal_password);

		for (auto& c : consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::cout << universal_password << std::endl;
					c.is_broken = true;
				}
			}
		}
	}

	while (1)
	{
		number = std::to_string(k);
		for (int i = 0; i < dictionary.size(); i ++)
		{
			small_password = number + dictionary[i] + number;
			medium_password = dictionary[i];
			medium_password[0] = toupper(medium_password[0]);
			medium_password = number + medium_password + number;
			big_password = dictionary[i];
			for (int h = 0; h < big_password.size(); h++)
			{
				big_password[h] = toupper(big_password[h]);
			}
			big_password = number + big_password + number;

			hash = md5(small_password);

			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << small_password << std::endl;
						c.is_broken = true;
					}
				}
			}

			hash = md5(medium_password);
			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << medium_password << std::endl;

						c.is_broken = true;
					}
				}
			}

			hash = md5(big_password);
			for (auto& c : consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::cout << big_password << std::endl;
						c.is_broken = true;
					}
				}
			}
		}
	}

}

void Producents::Producent4(std::vector<Consument>& consumer)
{
	std::cout << "siema";
}

void Producents::Producent5(std::vector<Consument>& consumer)
{
	std::cout << "siema";
}

void Producents::Producent6(std::vector<Consument>& consumer)
{
	std::cout << "siema";
}

void Producents::Producent7(std::vector<Consument>& consumer)
{
	std::cout << "siema";
}

void Producents::LoadingData(std::vector<Consument>& consumer)
{
	//Wczytanie slownika
	std::string tmpline;
	std::ifstream dictionary1("dictionary1.txt");
	while (std::getline(dictionary1, tmpline))
		dictionary.push_back(tmpline);



	//Wczytanie dane uzytkownikow (email oraz zahaszowane haslo)
	std::ifstream users_passwords("passwords.txt");
	std::string email, password;


	while (users_passwords >> email >> password)
	{
		Consument tmpconsument;
		tmpconsument.email = email;
		tmpconsument.hash_password = password;
		tmpconsument.is_broken = false;
		consumer.push_back(tmpconsument);
	}

}







