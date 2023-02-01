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
	std::thread t1(&Producents::Producent1, this, &consumers);
	std::thread t2(&Producents::Producent2, this, &consumers);
	std::thread t3(&Producents::Producent3, this, &consumers);
	std::thread t4(&Producents::Producent4, this, &consumers);
	std::thread t5(&Producents::Producent5, this, &consumers);
	std::thread t6(&Producents::Producent6, this, &consumers);
	std::thread t7(&Producents::Producent7, this, &consumers);
	std::thread screen(&Producents::Screen, this, &consumers);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	screen.join();
	
}

void Producents::Producent1(std::vector<Consument>* consumer)
{
	std::string universal_password, small_password, medium_password, big_password, hash, number;
	for (int i = 0; i < dictionary.size(); i += 3)
	{
		universal_password = dictionary[i];
		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{

					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}

		universal_password[0] = toupper(universal_password[0]);
		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{

					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}

		for (int h = 0; h < universal_password.size(); h++)
		{
			universal_password[h] = toupper(universal_password[h]);
		}

		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{

					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}
	}

	for (int k = 0; k < 100; k++)
	{
		number = std::to_string(k);
		for (int i = 0; i < dictionary.size(); i ++)
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

			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = small_password;
						c.is_broken = true;
						screen_passwords.push_back(small_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			hash = md5(medium_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = medium_password;
						c.is_broken = true;
						screen_passwords.push_back(medium_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			hash = md5(big_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = big_password;
						c.is_broken = true;
						screen_passwords.push_back(big_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}
		}
	}
}

void Producents::Producent2(std::vector<Consument>* consumer)
{
	std::string universal_password, small_password, medium_password, big_password, hash, number;

	for (int i = 1; i < dictionary.size(); i += 3)
	{

		universal_password = dictionary[i];
		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}

		universal_password[0] = toupper(universal_password[0]);
		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}

		for (int h = 0; h < universal_password.size(); h++)
		{
			universal_password[h] = toupper(universal_password[h]);
		}

		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}
	}

	for (int k = 0; k < 100; k++)
	{
		number = std::to_string(k);
		for (int i = 0; i < dictionary.size(); i++)
		{
			small_password = dictionary[i] + number;
			medium_password = dictionary[i];
			medium_password[0] = toupper(medium_password[0]);
			medium_password = medium_password + number;
			big_password = dictionary[i];
			for (int h = 0; h < big_password.size(); h++)
			{
				big_password[h] = toupper(big_password[h]);
			}
			big_password = big_password + number;

			hash = md5(small_password);

			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = small_password;
						c.is_broken = true;
						screen_passwords.push_back(small_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			hash = md5(medium_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = small_password;
						c.is_broken = true;
						screen_passwords.push_back(medium_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			hash = md5(big_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = big_password;
						c.is_broken = true;
						screen_passwords.push_back(big_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}
		}
	}

}

void Producents::Producent3(std::vector<Consument>* consumer)
{
	std::string universal_password, small_password, medium_password, big_password, hash, number;
	
	for (int i = 2; i < dictionary.size(); i += 3)
	{

		universal_password = dictionary[i];
		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}

		universal_password[0] = toupper(universal_password[0]);
		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}

		for (int h = 0; h < universal_password.size(); h++)
		{
			universal_password[h] = toupper(universal_password[h]);
		}

		hash = md5(universal_password);

		for (auto& c : *consumer)
		{
			if (c.is_broken == false)
			{
				if (hash == c.hash_password)
				{
					std::unique_lock<std::mutex> lock(_mutex);
					c.broken_password = universal_password;
					c.is_broken = true;
					screen_passwords.push_back(universal_password);
					cv.notify_one();
					lock.unlock();
				}
			}
		}
	}

	for(int k =0;k<dictionary.size();k++)
	{
		number = std::to_string(k);
		for (int i = 0; i < dictionary.size(); i++)
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

			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = small_password;
						c.is_broken = true;
						screen_passwords.push_back(small_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			hash = md5(medium_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = medium_password;
						c.is_broken = true;
						screen_passwords.push_back(medium_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			hash = md5(big_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{
					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = big_password;
						c.is_broken = true;
						screen_passwords.push_back(big_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}
		}
	}

}

void Producents::Producent4(std::vector<Consument>* consumer)
{
	std::string combine_password, hash, number;


	for (int f = 0; f < dictionary.size(); f += 3)
	{
		for (int s = 0; s < dictionary.size(); s += 3)
		{
			combine_password = dictionary[f] + dictionary[s];

			hash = md5(combine_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{

					if (hash == c.hash_password)
					{
						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = combine_password;
						c.is_broken = true;
						screen_passwords.push_back(combine_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			if (dictionary[f] != dictionary[s])
			{

				combine_password = dictionary[s] + dictionary[f];

				hash = md5(combine_password);
				for (auto& c : *consumer)
				{
					if (c.is_broken == false)
					{
						if (hash == c.hash_password)
						{
							std::unique_lock<std::mutex> lock(_mutex);
							c.broken_password = combine_password;
							c.is_broken = true;
							screen_passwords.push_back(combine_password);
							cv.notify_one();
							lock.unlock();
						}
					}
				}
			}

		}
	}

	for (int k = 0; k < 100; k++)
	{
		number = std::to_string(k);
		for (auto& f : dictionary)
		{
			for (auto& s : dictionary)
			{

				combine_password = number + f + s;

				hash = md5(combine_password);
				for (auto& c : *consumer)
				{
					if (c.is_broken == false)
					{
						if (hash == c.hash_password)
						{

							std::unique_lock<std::mutex> lock(_mutex);
							c.broken_password = combine_password;
							c.is_broken = true;
							screen_passwords.push_back(combine_password);
							cv.notify_one();
							lock.unlock();
						}
					}
				}

				if (f != s)
				{

					combine_password = number + s + f;

					hash = md5(combine_password);
					for (auto& c : *consumer)
					{
						if (c.is_broken == false)
						{
							if (hash == c.hash_password)
							{

								std::unique_lock<std::mutex> lock(_mutex);
								c.broken_password = combine_password;
								c.is_broken = true;
								screen_passwords.push_back(combine_password);
								cv.notify_one();
								lock.unlock();
							}
						}
					}
				}
			}
		}
	}
};

void Producents::Producent5(std::vector<Consument>* consumer)
{
	std::string combine_password, hash, number;


	for (int f = 1; f < dictionary.size(); f += 3)
	{
		for (int s = 1; s < dictionary.size(); s += 3)
		{
			combine_password = dictionary[f] + dictionary[s];

			hash = md5(combine_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{

					if (hash == c.hash_password)
					{

						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = combine_password;
						c.is_broken = true;
						screen_passwords.push_back(combine_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			if (dictionary[f] != dictionary[s])
			{

				combine_password = dictionary[s] + dictionary[f];

				hash = md5(combine_password);
				for (auto& c : *consumer)
				{
					if (c.is_broken == false)
					{
						if (hash == c.hash_password)
						{

							std::unique_lock<std::mutex> lock(_mutex);
							c.broken_password = combine_password;
							c.is_broken = true;
							screen_passwords.push_back(combine_password);
							cv.notify_one();
							lock.unlock();
						}
					}
				}
			}

		}
	}

	for (int k = 0; k < 100; k++)
	{
		number = std::to_string(k);
		for (auto& f : dictionary)
		{
			for (auto& s : dictionary)
			{

				combine_password = f + number + s;

				hash = md5(combine_password);
				for (auto& c : *consumer)
				{
					if (c.is_broken == false)
					{
						if (hash == c.hash_password)
						{

							std::unique_lock<std::mutex> lock(_mutex);
							c.broken_password = combine_password;
							c.is_broken = true;
							screen_passwords.push_back(combine_password);
							cv.notify_one();
							lock.unlock();
						}
					}
				}

				if (f != s)
				{

					combine_password = s + number + f;

					hash = md5(combine_password);
					for (auto& c : *consumer)
					{
						if (c.is_broken == false)
						{
							if (hash == c.hash_password)
							{

								std::unique_lock<std::mutex> lock(_mutex);
								c.broken_password = combine_password;
								c.is_broken = true;
								screen_passwords.push_back(combine_password);
								cv.notify_one();
								lock.unlock();
							}
						}
					}
				}
			}
		}
	}
};

void Producents::Producent6(std::vector<Consument>* consumer)
{
	std::string combine_password, hash, number;


	for (int f = 2; f < dictionary.size(); f += 3)
	{
		for (int s = 2; s < dictionary.size(); s += 3)
		{
			combine_password = dictionary[f] + dictionary[s];

			hash = md5(combine_password);
			for (auto& c : *consumer)
			{
				if (c.is_broken == false)
				{

					if (hash == c.hash_password)
					{

						std::unique_lock<std::mutex> lock(_mutex);
						c.broken_password = combine_password;
						c.is_broken = true;
						screen_passwords.push_back(combine_password);
						cv.notify_one();
						lock.unlock();
					}
				}
			}

			if (dictionary[f] != dictionary[s])
			{

				combine_password = dictionary[s] + dictionary[f];

				hash = md5(combine_password);
				for (auto& c : *consumer)
				{
					if (c.is_broken == false)
					{
						if (hash == c.hash_password)
						{

							std::unique_lock<std::mutex> lock(_mutex);
							c.broken_password = combine_password;
							c.is_broken = true;
							screen_passwords.push_back(combine_password);
							cv.notify_one();
							lock.unlock();
						}
					}
				}
			}

		}
	}

	for (int k = 0; k < 100; k++)
	{
		number = std::to_string(k);
		for (auto& f : dictionary)
		{
			for (auto& s : dictionary)
			{

				combine_password = f + s + number;

				hash = md5(combine_password);
				for (auto& c : *consumer)
				{
					if (c.is_broken == false)
					{
						if (hash == c.hash_password)
						{

							std::unique_lock<std::mutex> lock(_mutex);
							c.broken_password = combine_password;
							c.is_broken = true;
							lock.unlock();
						}
					}
				}

				if (f != s)
				{

					combine_password = s + f + number;

					hash = md5(combine_password);
					for (auto& c : *consumer)
					{
						if (c.is_broken == false)
						{
							if (hash == c.hash_password)
							{

								std::unique_lock<std::mutex> lock(_mutex);
								c.broken_password = combine_password;
								c.is_broken = true;
								lock.unlock();
							}
						}
					}
				}
			}
		}
	}
};

void Producents::Producent7(std::vector<Consument>* consumer)
{
	{
		std::string combine_password, hash, number;


		for (int f = 0; f < dictionary.size(); f += 3)
		{
			for (int s = 0; s < dictionary.size(); s += 3)
			{
				combine_password = dictionary[f] + dictionary[s];

				hash = md5(combine_password);
				for (auto& c : *consumer)
				{
					if (c.is_broken == false)
					{

						if (hash == c.hash_password)
						{

							std::unique_lock<std::mutex> lock(_mutex);
							c.broken_password = combine_password;
							c.is_broken = true;
							screen_passwords.push_back(combine_password);
							cv.notify_one();
							lock.unlock();
						}
					}
				}

				if (dictionary[f] != dictionary[s])
				{

					combine_password = dictionary[s] + dictionary[f];

					hash = md5(combine_password);
					for (auto& c : *consumer)
					{
						if (c.is_broken == false)
						{
							if (hash == c.hash_password)
							{

								std::unique_lock<std::mutex> lock(_mutex);
								c.broken_password = combine_password;
								c.is_broken = true;
								screen_passwords.push_back(combine_password);
								cv.notify_one();
								lock.unlock();
							}
						}
					}
				}

			}
		}

		for (int k = 0; k < 100; k++)
		{
			number = std::to_string(k);
			for (auto& f : dictionary)
			{
				for (auto& s : dictionary)
				{

					combine_password = number + f + number + s + number;

					hash = md5(combine_password);
					for (auto& c : *consumer)
					{
						if (c.is_broken == false)
						{
							if (hash == c.hash_password)
							{

								std::unique_lock<std::mutex> lock(_mutex);
								c.broken_password = combine_password;
								c.is_broken = true;
								screen_passwords.push_back(combine_password);
								cv.notify_one();
								lock.unlock();
							}
						}
					}

					if (f != s)
					{

						combine_password = number + s + number + f + number;

						hash = md5(combine_password);
						for (auto& c : *consumer)
						{
							if (c.is_broken == false)
							{
								if (hash == c.hash_password)
								{

									std::unique_lock<std::mutex> lock(_mutex);
									c.broken_password = combine_password;
									c.is_broken = true;
									screen_passwords.push_back(combine_password);
									cv.notify_one();
									lock.unlock();
								}
							}
						}
					}
				}
			}
		}
	}
}

void Producents::Producent8(std::vector<Consument>* consumer)
{

}

void Producents::Screen(std::vector<Consument>* consumer)
{
	while (1)
	{	
		std::unique_lock<std::mutex> lock(_mutex);
		cv.wait(lock);
		cracked_screen_passwords++;
		lock.unlock();
		std::cout <<"zlamane haslo to  " <<screen_passwords[cracked_screen_passwords] <<std::endl;
	}
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







