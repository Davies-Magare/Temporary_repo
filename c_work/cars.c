#include <stdio.h>
#include <string.h>
#define STRSIZ 100
typedef struct{
    int day;
    int month;
    int year;
}date_t;
typedef struct{
    double total_capacity;
    double current_capacity;
}tank_t;
typedef struct{
    char make[STRSIZ];
    char model[STRSIZ];
    int odometer_read;
    date_t manfacture_date;
    date_t purchase_date;
    tank_t tank;
}auto_t;
auto_t scan_auto(FILE *file, int *status);
date_t scan_date(FILE *file, int *status);
tank_t scan_tank(FILE *file, int *status);
void print_date(date_t date); 
void print_auto(auto_t car);
void print_tank(tank_t tank);
int main(void)
{
    auto_t car;
    FILE *file;
    int status;

    status = 1;
    file = fopen("cars.txt", "r");
    if (file == NULL)
	perror("fopen");
    else
    {
	
    	while (status != EOF)
    	{
        	car = scan_auto(file, &status);
		if (status != EOF)
		{
			printf("\n\n");
        		print_auto(car);
		}
    	}
    	fclose(file);
    }
    return (0);

}
auto_t scan_auto(FILE *file, int *status)
{
    auto_t car;

    *status = fscanf(file, "%s%s%i", car.make, car.model, &car.odometer_read);
    car.manfacture_date = scan_date(file, status);
    car.purchase_date = scan_date(file, status);
    car.tank = scan_tank(file, status);
    if (status) 
    	return (car);
}
date_t scan_date(FILE *file, int *status)
{
    date_t date;

    *status = fscanf(file, "%i%i%i", &date.day, &date.month, &date.year);
    return (date);
}
tank_t scan_tank(FILE *file, int *status)
{
    tank_t tank;

    *status = fscanf(file, "%lf%lf", &tank.total_capacity, &tank.current_capacity);
    return (tank);   
}
void print_auto(auto_t car)
{
    printf("Make: %s\nModel: %s\nOdometer Reading: %i\n", car.make, car.model, car.odometer_read);
    printf("Manfacture date: \n");
    print_date(car.manfacture_date);
    printf("Purchase Date: \n");
    print_date(car.purchase_date);
    printf("Tank details: \n");
    print_tank(car.tank);
}
void print_date(date_t date)
{
    printf("Day: %i\nMonth: %i\nYear: %i\n", date.day, date.month, date.year);
}
void print_tank(tank_t tank)
{
    printf("Total Capacity: %.2f gallons\n", tank.total_capacity);
    printf("Current Capacity: %.2f gallons\n", tank.current_capacity);
}
