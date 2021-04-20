#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

struct tim
{
	int day;
	int year;
	int month;
};

struct signs
{
	int age;
	char color[20];
	char name[20];
	int weighеt;
};


struct Cat
{
	tim date;
	signs sign;
};

Cat cat;

int main()
{
	FILE* file;

	setlocale(LC_ALL, "Russian");

	while (true)
	{
		system("cls");

		int option;

		printf("1.Добавить котика\n");
		printf("2.Вывести всех котиков\n");
		printf("3.Выход\n");
		scanf_s("%d", &option);
		while (getchar() != '\n') {
			continue;
		}


		if (option == 1)
		{
			char cbuffer[20];
			int ibuffer;

			system("cls");
			fopen_s(&file, "xXx_cat_xXx.txt", "a+");

			printf("Введите имя котика:");
			gets_s(cbuffer);
			fprintf(file, "%s ", cbuffer);
			*cbuffer = '\0';

			printf("Введите день поступления котика в приют:");
			scanf_s("%d", &ibuffer);
			while (getchar() != '\n') {
				continue;
			}
			fprintf(file, "%d ", ibuffer);

			printf("Введите месяц поступления котика в приют:");
			scanf_s("%d", &ibuffer);
			while (getchar() != '\n') {
				continue;
			}
			fprintf(file, "%d ", ibuffer);

			printf("Введите год поступления котика в приют:");
			scanf_s("%d", &ibuffer);
			while (getchar() != '\n') {
				continue;
			}
			fprintf(file, "%d ", ibuffer);

			printf("Введите возраст котика в годах:");
			scanf_s("%d", &ibuffer);
			while (getchar() != '\n') {
				continue;
			}
			fprintf(file, "%d ", ibuffer);

			printf("Введите цвет котика:");
			gets_s(cbuffer);
			fprintf(file, "%s ", cbuffer);
			*cbuffer = '\0';

			printf("Введите вес котика в килограмах:");
			scanf_s("%d", &ibuffer);
			while (getchar() != '\n') {
				continue;
			}
			fprintf(file, "%d ", ibuffer);
			fclose(file);
		}

		else if (option == 2)
		{
			system("cls");
			fopen_s(&file, "xXx_cat_xXx.txt", "r");

			while (!feof(file))
			{
				if (fscanf_s(file, "%s", cat.sign.name, _countof(cat.sign.name)) > 0)
				{
					fscanf_s(file, "%d", &cat.date.day);
					fscanf_s(file, "%d", &cat.date.month);
					fscanf_s(file, "%d", &cat.date.year);
					fscanf_s(file, "%d", &cat.sign.age);
					fscanf_s(file, "%s", cat.sign.color, _countof(cat.sign.color));
					fscanf_s(file, "%d", &cat.sign.weighеt);
					printf("Имя котика: %s\nДата поступления в приют: %d:%d:%d\nВозраст(в годах): %d\nЦвет: %s\nВес(в килограмах): %d\n", cat.sign.name, cat.date.day, cat.date.month, cat.date.year, cat.sign.age, cat.sign.color, cat.sign.weighеt);
					*cat.sign.color = *cat.sign.name = '\0';
				}
			}
			_getch();
			fclose(file);
		}

		else if (option == 3)
		{
			break;
		}



	}
}