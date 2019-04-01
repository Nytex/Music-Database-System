#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<iomanip>
#include <conio.h>

int main() {


	FILE* fp, *ft; //point to two file
	fp = fopen("main.txt", "rb+"); //main file
	ft = fopen("temp.dat", "rb+"); //temp file for replacement in delete

	//Other Comment
	char another;
	char option;
	char search[50];
	unsigned int temp_id;
	int tries = 0;


	//data structure
	struct data {
		unsigned int id;
		char song_name[50];
		char singer_name[50];
		char language[20];
		double length;
	};
	//structured e for the data
	struct data e;
	int resize = sizeof(e);

	//Check file Valid
	if (fp == NULL) {
		fopen("main.txt", "wb+");
		if (fp == NULL)
		{
			std::cout << "Cannot open or create the file";
			return 0;
		}

	}

	//If file valid
	while (true) {
		system("CLS");
		std::cout << "=== Welcome to Songs Database Management System ===\n";
		std::cout << "Please enter the number of option you need: \n";
		std::cout << "1 Add Song Data\n";
		std::cout << "2 View Song Data\n";
		std::cout << "3 Modify Song Data\n";
		std::cout << "4 Delete Song Data\n";
		std::cout << "5 Exit\n";
		std::cout << "Enter your Option here:";
		fflush(stdin);
		std::cin >> option;

		switch (option) {
		case '1':
			//Add Data
			fseek(fp, 0, SEEK_END);
			another = 'Y';
			while (another == 'Y' || another == 'y') {
				system("CLS");
				std::cout << "Insert the id of the songs: ";
				std::cin >> e.id;
				std::cout << "\nInsert the Name of the Songs: ";
				std::cin >> e.song_name;
				std::cout << "\nInsert the Singer Name of the Songs: ";
				std::cin >> e.singer_name;
				std::cout << "\nInsert the Language of the Songs: ";
				std::cin >> e.language;
				std::cout << "\nInsert the Duration of the Songs: ";
				std::cin >> e.length;
				fwrite(&e, resize, 1, fp);
				fflush(stdin);
				std::cout << "Do you want to add another record? (Y/N) ";
				std::cin >> another;
			}
			break;

		case '2':
			//view data
			system("CLS");
			rewind(fp);
			while (fread(&e, resize, 1, fp) == true) {
				std::cout << e.id << "     " << e.song_name << "     " << e.singer_name << "     " << e.language << "     " << e.length << "\n";


			}
			system("pause");
			break;

		case '3':
			//Modify Data
			system("CLS");
			another = 'Y';
			while (another == 'Y' || another == 'y') {
				
					rewind(fp);
					while (fread(&e, resize, 1, fp) == true) {
						std::cout << "Insert the songs or singer name to search: ";
						std::cin >> search;

						if (strcmp(search, e.song_name) == 0) {
							std::cout << e.id << "     " << e.song_name << "     " << e.singer_name << "     " << e.language << "     " << e.length << "\n";
							std::cout << "(Caution: Wrongly insert ID may cause false modification!)\n";
							std::cout << "Please insert the id of the songs that you want to modify: ";
							std::cin >> temp_id;
							if (temp_id = e.id) {
								std::cout << "Data Found!\n";
								std::cout << "Please key in the New Song Name: ";
								std::cin >> e.song_name;
								std::cout << "\n";
								std::cout << "Please key in the New Singer Name: ";
								std::cin >> e.singer_name;
								std::cout << "\n";
								std::cout << "Please key in the New Language: ";
								std::cin >> e.language;
								std::cout << "\n";
								std::cout << "Please key in the New Music Length: ";
								std::cin >> e.length;
								std::cout << "\n";
								fseek(fp, -resize, SEEK_CUR);
								fwrite(&e, resize, 1, fp);
								break;
							}
							else {
								std::cout << "Please key in valid song ID! ";
								break;
							}
						}
						else if (strcmp(search, e.singer_name) == 0) {
							std::cout << e.id << "     " << e.song_name << "     " << e.singer_name << "     " << e.language << "     " << e.length << "\n";
							std::cout << "(Caution: Wrongly insert ID may cause false modification!)\n";
							std::cout << "Please insert the id of the songs that you want to MODIFY: ";
							std::cin >> temp_id;
							if (temp_id = e.id) {
								std::cout << "Data Found!\n";
								std::cout << "Please key in the New Song Name: ";
								std::cin >> e.song_name;
								std::cout << "\n";
								std::cout << "Please key in the New Singer Name: ";
								std::cin >> e.singer_name;
								std::cout << "\n";
								std::cout << "Please key in the New Language: ";
								std::cin >> e.language;
								std::cout << "\n";
								std::cout << "Please key in the New Music Length: ";
								std::cin >> e.length;
								std::cout << "\n";
								fseek(fp, -resize, SEEK_CUR);
								fwrite(&e, resize, 1, fp);
								break;
							}
							else {
								std::cout << "Please Key In Valid Song ID! ";
								break;
							}
						}

						else
						{
							std::cout << "\n===No Records Found!===\n";
							break;

						}


					}
					std::cout << "\nDo You Want to Modify Another Record (Y/N) ";
					std::cin >> another;
				
			}
			break;


		case '4':
			//delete file
			system("CLS");
			another = 'Y';
			while (another == 'Y' || another == 'y') {
					std::cout << "Insert the songs or singer name to search: ";
					std::cin >> search;
					ft = fopen("temp.dat", "wb+");
					rewind(fp);
					while (fread(&e, resize, 1, fp) == true) {
						if (strcmp(search, e.song_name) == 0 || (strcmp(search, e.singer_name) == 0)) {
							std::cout << e.id << "     " << e.song_name << "     " << e.singer_name << "     " << e.language << "     " << e.length << "\n";
							std::cout << "(Caution: Wrongly insert ID may cause false DELETE!)\n";
							std::cout << "Please insert the id of the songs that you want to DELETE: ";
							std::cin >> temp_id;
							if (temp_id = e.id) {
								fwrite(&e, resize, 1, ft);
								break;
							}
							else {
								std::cout << "Please key in valid song ID! ";
								break;
							}



						}
						else
						{
							std::cout << "\n===No Records Found!===\n";
							break;

						}
					}
					fclose(fp);
					fclose(ft);
					remove("main.txt");
					rename("temp.dat", "main.txt");

					fp = fopen("main.txt", "rb +");

					std::cout << "\nDo You Want to DELETE Another Record (Y/N) ";
					std::cin >> another;
										     				
				

			}
			break;


		case '5':
			fclose(fp);
			std::cout << "\n ====System Terminate!===";
			system("pause");
			exit(0);

		default: 
			std::cout << "\nPlease key in valid option!";
			system("pause");
			exit(0);

		
			
		



		}
		

		}
		system("pause");
		return 0;
	}