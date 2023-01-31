#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<thread>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<openssl/md5.h>


struct Consument
{
	std::string email;
	std::string hash_password;
	std::string broke_password;
	bool is_broken;
};


class Producents
{
public:
	void MainProducent();
	void Producent1(std::vector<Consument>& consumer);
	void Producent2(std::vector<Consument>& consumer);
	void Producent3(std::vector<Consument>& consumer);
	void Producent4(std::vector<Consument>& consumer);
	void Producent5(std::vector<Consument>& consumer);
	void Producent6(std::vector<Consument>& consumer);
	void Producent7(std::vector<Consument>& consumer);
	void LoadingData(std::vector<Consument>& consumers);
	;

private:
	std::vector<std::string> dictionary;
	;
};

