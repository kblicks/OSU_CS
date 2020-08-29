/*********************************************************************
** Program Filename: zoo.cpp
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: .cpp file for the zoo class
*********************************************************************/

#include "zoo.h"
#include "animal.h"
#include "monkey.h"
#include "sea_otter.h"
#include "sloth.h"

#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

/*********************************************************************
** Function: Zoo()
** Description: Default constructor of Zoo
** Parameters: none
** Pre-Conditions: Variables are unitialized
** Post-Conditions: Variables have been initialized
*********************************************************************/
Zoo::Zoo()
{
    vector<Animal *> animals;

    cout << "Default zoo constructor" << endl;
    this->total_animals = 0;
    this->total_money = 50000;
    this->start_money = 50000;
    this->m_purchases = 0;
    this->m_sales = 0;
    this->last_bought = 0;
    this->m_meds = 0;
    this->month = 1;
    this->attendance = 0;
    this->m_attendance_rev = 0;
    this->last_m_attrev = 0;
    this->m_feed_costs = 0;
    this->m_meds = 0;
    this->boom_food = 0;

    //initialize random generator
    srand(time(0));
}

/*********************************************************************
** Function: play_game()
** Description: Calls the functions in order to run the game
** Parameters: none
** Pre-Conditions: No game has started
** Post-Conditions: Game has been started and played through
*********************************************************************/
void Zoo::play_game()
{
    bool gameover = false;

    while (gameover == false)
    {
        if (month == 1)
        {
            menu();
            feeding_cost();
        }
        else
        {
            random_event();
            menu();
            feeding_cost();
        }

        calc_income();
        balance_sheet();

        set_month_revenue();
        get_last_month_rev();
        reset_m_vars();
        ageup();
        check_adulthood();
        gameover = check_gameover();
    }
}

/*********************************************************************
** Function: random_event()
** Description: Function for randomized an event each month
** Parameters: none
** Pre-Conditions: Random event hasn't occurred
** Post-Conditions: Random event picked
*********************************************************************/
void Zoo::random_event()
{
    int event_id = rand() % 4 + 1;
    this->boom_food = false;

    if (animals.size() > 0)
    {
        switch (event_id)
        {
        case 1: //sickness
            sickness();
            break;
        case 2: //birth
            birth();
            break;
        case 3: //boom
            boom_zoo();
            break;
        case 4:
            cout << "No special event this month" << endl;
            break;
        }
    }
    else
    {
        cout << "No special event this month" << endl;
    }
}

/*********************************************************************
** Function: sickness()
** Description: Randomly chooses an animal to get sick if there are animals in the zoo
** Parameters: none
** Pre-Conditions: Player doesn't have sick animals and has X amount of cash
** Post-Conditions: Animal got sick or didn't and player had to pay for meds, or animal died and is removed from zoo
*********************************************************************/
void Zoo::sickness()
{

    int infected = rand() % animals.size();

    cout << "Oh no! This animal got sick" << endl;
    animals[infected]->display_type();
    int age = animals[infected]->get_age();
    cout << "Age: " << age << " months old" << endl;

    float cure_price = 0;

    if (age < 6)
    {
        cure_price = 2 * animals[infected]->get_price();
    }
    else
    {
        cure_price = animals[infected]->get_price();
    }

    if (cure_price <= this->total_money)
    {
        cout << "You were able to cure the animal and " << cure_price << " was subtracted from your account" << endl;
        this->m_meds += cure_price;
        this->total_money -= cure_price;
    }
    else
    {
        cout << "You didn't have enough money and the animal died" << endl;
        Animal *aa = animals.at(infected);
        delete aa;
        animals.erase(animals.begin() + infected);
    }
}

/*********************************************************************
** Function: birth()
** Description: Randomly chooses an animal to get pregnant and give birth if animal is an adult
** Parameters: none
** Pre-Conditions: Animal not selected to give birth
** Post-Conditions: Animal selected and babies are added to the zoo if animal is an adult
*********************************************************************/
void Zoo::birth()
{

    int preggo = rand() % animals.size();
    int species = animals[preggo]->get_species();
    int age = animals[preggo]->get_age();
    int babies = animals[preggo]->get_n_babies();

    if (age >= 24)
    {
        cout << "Congratulations! Your ";
        animals[preggo]->display_type();
        cout << "Has given birth to " << babies << " babies. They have been added to your zoo" << endl;

        if (species == 1)
        {
            animals.push_back(new Monkey(0));
        }
        else if (species == 2)
        {
            animals.push_back(new Sea_otter(0));
            animals.push_back(new Sea_otter(0));
        }
        else if (species == 3)
        {
            animals.push_back(new Sloth(0));
            animals.push_back(new Sloth(0));
            animals.push_back(new Sloth(0));
            animals.push_back(new Sloth(0));
        }
    }
}

/*********************************************************************
** Function: boom_zoo()
** Description: Special event that causes a boom in attendance and doubles the base food cost
** Parameters: none
** Pre-Conditions: Attendance and base food cost are 1x
** Post-Conditions: Attendance and base food cost are 2x
*********************************************************************/
void Zoo::boom_zoo()
{

    cout << "Attendance is booming and another $" << this->last_m_attrev << " has been added to the bank!" << endl;
    //add_revenue();
    this->total_money += this->last_m_attrev;
    this->last_m_attrev += this->last_m_attrev;

    //this->m_attendance_rev += this->last_m_attrev;

    cout << "All this excitement has made your animals ravenous and the base cost of food has also doubled" << endl;
    this->boom_food = true;
}

/*********************************************************************
** Function: menu()
** Description: Function that holds the menu options and prompts user to choose an action
** Parameters: none
** Pre-Conditions: User has nt input an option
** Post-Conditions: Option is inputted by user and corresponding function is called
*********************************************************************/
void Zoo::menu()
{
    int input = 0;
    this->bought = 0;
    this->sold = 0;
    add_speciesstats();
    print_status();
    while (input != 3)
    {
        int act = 0;

        cout << "Select an option below: " << endl;
        cout << "1) Buy animal" << endl;
        cout << "2) Sell animal" << endl;
        cout << "3) Proceed to next month" << endl;
        cout << "4) View zoo" << endl;
        cout << "5) Quit game" << endl;

        while (act == 0)
        {
            input = check_int_input();
            if (input == 1 && bought >= 2)
            {
                cout << "You've already bought enough animals this month" << endl;
                act = -1;
                input = 0;
            }
            else if (input == 2 && sold >= 1)
            {
                cout << "You've already sold an animal this month" << endl;
                act = -1;
                input = 0;
            }
            else if (input == 3)
            {
                cout << "Proceeding to the next month" << endl;
                act = -1;
                input = 3;
            }
            else if (input == 4)
            {
                print_zoolist();
                act = -1;
                input = 0;
            }
            else if (input == 5)
            {
                cout << "Goodbye!" << endl;
                del_vector();
                exit(EXIT_FAILURE);
            }
            else
            {
                act = action(input);
                input = 0;
            }
        }
    }
}

/*********************************************************************
** Function: action
** Description: Takes in user choice and calls function for the action
** Parameters: int
** Pre-Conditions: input from user is taken
** Post-Conditions: action that corresponds to input calls the function
*********************************************************************/
int Zoo::action(int input)
{

    switch (input)
    {
    case 1:
        choose_animal_buy();
        return -1;
        break;
    case 2:
        choose_animal_sell();
        return -1;
        break;
    default:
        cout << "That's not an option" << endl;
        return 0;
    }
}

/*********************************************************************
** Function: buy_animal()
** Description: Adds the selected animal to the zoo
** Parameters: int
** Pre-Conditions: Animal selected hasn't been added to zoo
** Post-Conditions: Animal is added to zoo and vector size increases
*********************************************************************/
int Zoo::buy_animal(int animal)
{

    if (animal >= 1 && animal <= 3)
    {
        this->bought++;
        switch (animal)
        {
        case 1:
            animals.push_back(new Monkey());
            this->m_purchases += 15000;
            this->last_bought = 1;
            return 1;
            break;
        case 2:
            animals.push_back(new Sea_otter());
            this->m_purchases += 5000;
            this->last_bought = 2;
            return 2;
            break;
        case 3:
            animals.push_back(new Sloth());
            this->m_purchases += 2500;
            this->last_bought = 3;
            return 3;
            break;
        }
    }
    else
    {
        cout << "That's not an animal option, please try again" << endl;
        return 0;
    }
}

/*********************************************************************
** Function: choose_animal_buy()
** Description: Asks user to choose which animal they would like to buy
** Parameters: none
** Pre-Conditions: User hasn't chosen an animal
** Post-Conditions: User has input a choice
*********************************************************************/
void Zoo::choose_animal_buy()
{
    int animal = 0;
    int buy = 0;
    while (buy == 0)
    {

        cout << "What animal do you want to buy?" << endl;
        cout << "1: Monkey | $15,000" << endl;
        cout << "2: Sea Otter | $5,000" << endl;
        cout << "3: Sloth | $2,500" << endl;
        cout << "4: No animal" << endl;
        animal = check_int_input();
        if (animal == 4)
        {
            buy = -1;
        }
        else
        {
            if (this->bought == 1)
            {
                if (animal != this->last_bought)
                {
                    cout << "You may only buy another animal of the same species" << endl;
                    buy = 0;
                }
                else
                {
                    buy = buy_animal(animal);
                }
            }
            else
            {
                buy = buy_animal(animal);
            }
        }
    }
}

/*********************************************************************
** Function: choose_animal_sell()
** Description: User is asked to choose which animal they want to sell
** Parameters: none
** Pre-Conditions: User hasn't chosen an animal to sell
** Post-Conditions: User has input an answer for which animal to sell
*********************************************************************/
void Zoo::choose_animal_sell()
{
    this->total_animals = animals.size();
    if (this->total_animals == 0)
    {
        cout << "You currently have no animals in your zoo to sell" << endl;
    }
    else
    {
        int animal = 0;
        int sell = 0;
        while (sell == 0)
        {
            cout << "Enter the ID of the animal you want to sell. Enter an ID that doesn't exist if you decide you don't want to sell" << endl;
            cout << "Here are the prices" << endl;
            cout << "Monkey | $7,500" << endl;
            cout << "Sea Otter | $2,500" << endl;
            cout << "Sloth | $1,250" << endl;
            cout << endl;

            print_zoolist();
            animal = check_int_input();
            sell = sell_animal(animal);
        }
    }
}

/*********************************************************************
** Function: sell_animal()
** Description: Function sells the animal the user has picked and adds the money to bank. Removes the animal from the vector
** Parameters: int
** Pre-Conditions: Vector is size Y and there is X money in the bank
** Post-Conditions: Vector is size Y-1 and money has been subtracted from the bank
*********************************************************************/
int Zoo::sell_animal(int animal)
{

    if (animal >= 0 && animal <= animals.size())
    {
        this->m_sales += animals[animal]->get_price();
        Animal *aa = animals.at(animal);
        delete aa;
        animals.erase(animals.begin() + animal);
        // vector<Animal *>::iterator new_end;
        //  new_end = remove(animals.begin(), animals.end(), animals.at(animal));
        //  Animal *ans = animals.at(animals.begin() + animal);
        sold++;
        return -1;
    }
    else
    {
        cout << "That animal ID does not exist, try again" << endl;
        return -1;
    }
}

/*********************************************************************
** Function: ageup()
** Description: Ages all the animals in the zoo +1
** Parameters: none
** Pre-Conditions: Animal is age X
** Post-Conditions: Animal is age X+1
*********************************************************************/
void Zoo::ageup()
{

    for (int i = 0; i < animals.size(); i++)
    {
        animals[i]->add_age(animals[i]->get_age());
    }
}

/*********************************************************************
** Function: print_zoolist()
** Description: Prints the stats of the zoo and all the animals
** Parameters: none
** Pre-Conditions: Animals in zoo not displayed
** Post-Conditions: Animals displayed to console
*********************************************************************/
void Zoo::print_zoolist()
{

    this->total_animals = animals.size();
    cout << "This zoo has: " << this->total_animals << " animals" << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i < this->total_animals; i++)
    {
        cout << "ID: " << i << endl;
        animals[i]->display_type();
        int age = animals[i]->get_age();
        cout << "Age: " << age << " months old" << endl;
        cout << "======================" << endl;
    }
}

/*********************************************************************
** Function: print_status()
** Description: Prints the status of the zoo and how many adults/babies there are of each species
** Parameters: none
** Pre-Conditions: Stats not displayed
** Post-Conditions: Stats displayed to console
*********************************************************************/
void Zoo::print_status()
{
    this->total_animals = animals.size();
    cout << endl;
    cout << "Month " << this->month << " Update" << endl;
    cout << "_________________________" << endl;
    cout << "Money: " << this->total_money << endl;
    cout << "Animals: " << this->total_animals << endl;
    cout << endl;
    cout << "Monkeys" << endl;
    cout << "Adults: " << this->num_adult_monkeys << " Babies: " << this->num_baby_monkeys << endl;
    cout << endl;
    cout << "Sea Otters" << endl;
    cout << "Adults: " << this->num_adult_otters << " Babies: " << this->num_baby_otters << endl;
    cout << endl;
    cout << "Sloths" << endl;
    cout << "Adults: " << this->num_adult_sloths << " Babies: " << this->num_baby_sloths << endl;
    cout << "_________________________" << endl;
}

/*********************************************************************
** Function: add_speciesstats
** Description: Function to count num adults/babies for each species 
** Parameters: none
** Pre-Conditions: num species not counted
** Post-Conditions: num species counted
*********************************************************************/
void Zoo::add_speciesstats()
{
    this->num_adult_monkeys = 0;
    this->num_baby_monkeys = 0;
    this->num_adult_otters = 0;
    this->num_baby_otters = 0;
    this->num_adult_sloths = 0;
    this->num_baby_sloths = 0;
    for (int i = 0; i < animals.size(); i++)
    {
        int age = animals[i]->get_age();
        int species = animals[i]->get_species();

        if (species == 1 && age >= 24)
        {
            this->num_adult_monkeys++;
        }
        else if (species == 1 && age < 6)
        {
            this->num_baby_monkeys++;
        }
        else if (species == 2 && age >= 24)
        {
            this->num_adult_otters++;
        }
        else if (species == 2 && age < 6)
        {
            this->num_baby_otters++;
        }
        else if (species == 3 && age >= 24)
        {
            this->num_adult_sloths++;
        }
        else if (species == 3 && age < 6)
        {
            this->num_baby_sloths++;
        }
    }
}

/*********************************************************************
** Function: feeding_cost()
** Description: Calculates the feeding cost for the month based on the animals in the zoo
** Parameters: none
** Pre-Conditions: Food costs not calculated
** Post-Conditions: Food costs are calculated
*********************************************************************/
void Zoo::feeding_cost()
{
    set_species_totals();
    this->food_cost = 0;
    float month_cost = rand() % 125 + 75;
    float monkey_cost = 4 * month_cost * this->num_monkeys;
    float otter_cost = 2 * month_cost * this->num_sea_otters;
    float sloth_cost = month_cost * this->num_sloths;
    //The end of the first month uses starting base cost $100
    if (month == 2)
    {
        this->food_cost = (100 * 4 * this->num_monkeys) + (100 * 2 * this->num_sea_otters) + (100 * this->num_sloths);
    }
    else
    {
        this->food_cost = monkey_cost + otter_cost + sloth_cost;
    }

    if (this->boom_food == true)
    {
        this->m_feed_costs += this->food_cost * 2;
    }
    else
    {
        this->m_feed_costs += this->food_cost;
    }
}

/*********************************************************************
** Function: check_adulthood()
** Description: Checks to see if a baby can be given adolescent status and adult traits
** Parameters: none
** Pre-Conditions: Animal has baby traits
** Post-Conditions: Animal has adult traits
*********************************************************************/
void Zoo::check_adulthood()
{
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i]->get_age() == 6)
        {
            animals[i]->set_adult();
        }
    }
}

/*********************************************************************
** Function: set_speciess_totals() 
** Description: Initializes and sets the species totals
** Parameters: none
** Pre-Conditions: Species totals not set
** Post-Conditions: Species totals are set
*********************************************************************/
void Zoo::set_species_totals()
{
    this->num_monkeys = 0;
    this->num_sea_otters = 0;
    this->num_sloths = 0;
    for (int i = 0; i < animals.size(); i++)
    {
        int species = animals[i]->get_species();
        if (species == 1)
        {
            this->num_monkeys++;
        }
        else if (species == 2)
        {
            this->num_sea_otters++;
        }
        else if (species == 3)
        {
            this->num_sloths++;
        }
    }
}

/*********************************************************************
** Function: add_revenue()
** Description: Adds the monthly revenue to bank
** Parameters: none
** Pre-Conditions: Total money is X
** Post-Conditions: Total money is X + monthly revenue
*********************************************************************/
void Zoo::add_revenue()
{
    cout << this->m_attendance_rev << " attendance revenue has been added to the bank" << endl;
    this->total_money += this->m_attendance_rev;
}

/*********************************************************************
** Function: set_month_revenue()
** Description: Calculates the monthly revenue based on attendance
** Parameters: none
** Pre-Conditions: Attendance revenue is not calculated 
** Post-Conditions: Attendance revenue is calculated
*********************************************************************/
void Zoo::set_month_revenue()
{
    this->total_animals = animals.size();

    if (this->total_animals == 0)
    {
        cout << "No animals present to generate revenue for this month" << endl;
    }
    else
    {
        this->attendance = rand() % (100 * animals.size()) + (50 * animals.size());
        for (int i = 0; i < animals.size(); i++)
        {
            this->m_attendance_rev += this->attendance * animals[i]->get_revenue();
        }
        cout << this->attendance << " Attended the zoo this month" << endl;
        add_revenue();
    }
}

/*********************************************************************
** Function: get_last_month_rev
** Description: Sets last months revenue as current for displaying in balance sheet
** Parameters: none
** Pre-Conditions: Last month revenue not set
** Post-Conditions: Last month rev = this months rev
*********************************************************************/
void Zoo::get_last_month_rev()
{
    this->last_m_attrev = this->m_attendance_rev;
}

/*********************************************************************
** Function: calc_income
** Description: Calculates the gross profits for the month and the bank
** Parameters: none
** Pre-Conditions: Total money for the month not updated
** Post-Conditions: Total money for the month is updated
*********************************************************************/
void Zoo::calc_income()
{
    float gross = m_sales - m_purchases - m_feed_costs;
    this->total_money = this->total_money + gross;
}

/*********************************************************************
** Function: balance_sheet()
** Description: Displayed the income statement for a month
** Parameters: none
** Pre-Conditions: Income statement not displayed
** Post-Conditions: Income statement is displayed
*********************************************************************/
void Zoo::balance_sheet()
{
    cout << endl;
    cout << "Month " << this->month << " Income Statement" << endl;
    cout << "==========================" << endl;
    cout << "BEGINNING BALANCE: $" << this->start_money << endl;
    cout << "_________" << endl;
    cout << "Revenue: " << endl;
    cout << "    Sales: " << this->m_sales << endl;
    cout << "   Attendance: " << this->last_m_attrev << endl;
    cout << endl;
    cout << "Expenses: " << endl;
    cout << "   Purchases: " << this->m_purchases << endl;
    cout << "   Feed costs: " << this->m_feed_costs << endl;
    cout << "   Medications: " << this->m_meds << endl;
    cout << "_________" << endl;
    cout << "ENDING BALANCE: $" << this->total_money << endl;
    cout << "==========================" << endl;
    cout << endl;
    //reset Beginning balance to equal ending balance of last income sheet
    this->start_money = this->total_money;
}

/*********************************************************************
** Function: check_gameover()
** Description: Checks to see if game is over and returns a true or false when a condition is satisfied
** Parameters: none
** Pre-Conditions: Game is not over
** Post-Conditions: Game is over or continues
*********************************************************************/
bool Zoo::check_gameover()
{
    //Lose condition
    if (this->total_money <= 0)
    {
        cout << "============================" << endl;
        cout << "||      GAME IS OVER      ||" << endl;
        cout << "============================" << endl;
        cout << "Your zoo has gone bankrupt! Game over" << endl;
        return true;
    }
    //Win condition
    else if (this->total_money >= 500000)
    {
        cout << "============================" << endl;
        cout << "||      GAME IS OVER      ||" << endl;
        cout << "============================" << endl;
        cout << "Your zoo is so rich it's time to retire. You've won!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

/*********************************************************************
** Function: reset_m_vars()
** Description: Ressets the monthly variables back to zero
** Parameters: none
** Pre-Conditions: Monthly variables are initialized with values
** Post-Conditions: Monthly variables are set back to 0
*********************************************************************/
void Zoo::reset_m_vars()
{
    this->m_purchases = 0;
    this->m_sales = 0;
    this->m_attendance_rev = 0;
    this->m_meds = 0;
    this->m_feed_costs = 0;

    //Move forward a month
    this->month++;
    //Reset what animal was bought from last month
    this->last_bought = 0;
}

/*********************************************************************
** Function: del_vector()
** Description: Deletes the animals vector that holds the animals for the zoo
** Parameters: none
** Pre-Conditions: Vector full of pointers
** Post-Conditions: Pointers are deleted and vector is reset
*********************************************************************/
void Zoo::del_vector()
{
    for (int i = 0; i < animals.size(); i++)
    {
        Animal *ans = animals.at(i);
        delete ans;
        // ans = NULL;
    }
    animals.clear();
    vector<Animal *>().swap(animals);
    //  cout << "Size: " << animals.size() << endl;
    //   cout << "cap: " << animals.capacity() << endl;
}

/*********************************************************************
** Function: play_again()
** Description: Asks the user if they want to play again and returns a true or false  
** Parameters: none
** Pre-Conditions: Game has ended
** Post-Conditions: Program either quits or game starts over
*********************************************************************/
bool Zoo::play_again()
{

    string play_again;

    int answer = 0;
    while (answer == 0)
    {

        cout << "Type in 'yes' to play again or 'no' to quit" << endl;
        getline(cin, play_again);
        if (play_again == "yes")
        {
            return true;
        }
        else if (play_again == "no")
        {
            return false;
        }
        else
        {
            cout << "That's not a valid input, please try again" << endl;
            answer = 0;
        }
    }
}

/*********************************************************************
** Function: check_int_input()
** Description: Checks the input and makes sure it isn't empty or a non integer value
** Parameters: none
** Pre-Conditions: User input hasn't been checked
** Post-Conditions: User input has been accepted
*********************************************************************/
int Zoo::check_int_input()
{
    cin.clear();
    string input_str;
    int input;
    getline(cin, input_str);

    if (input_str == "")
    {
        cout << "Nothing was entered" << endl;
        return -1;
    }

    while (cin.fail() || cin.eof() || input_str.find_first_not_of("0123456789") != string::npos)
    {
        if (input_str.find_first_not_of("0123456789") == string::npos)
        {
            cin.clear();
            cin.ignore(256, '\n');
        }

        cout << " Re-Enter a valid input " << endl;
        getline(cin, input_str);
        if (input_str == "")
        {
            cout << "Nothing was entered" << endl;
            return -1;
        }
    }

    input = atoi(input_str.c_str());
    return input;
}