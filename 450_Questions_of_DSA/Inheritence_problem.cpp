#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        Student(string firstName, string lastName, int identification, vector<int> scores)
        : Person(firstName, lastName, identification)
        {
            // for(int i=0; i<scores.size(); i++){
            //     cout<<"this runs \n";
            //     this->testScores[i] = scores[i];
            // }
            // cout<<"this runs \n";
            testScores=scores;
        }
        

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        char calculate(){
            int sum=0, avg=0;
            for(int i=0; i<testScores.size(); i++){
                sum += testScores[i];
            }
            avg = sum/testScores.size();
            if(avg>=90 && avg<=100)
                return 'O';
            else if (avg<90 && avg>=80)
                return 'E';
            else if (avg<80 && avg>=70)
                return 'A';
            else if (avg<70 && avg>=55)
                return 'P';
            else if (avg<55 && avg>=40)
                return 'D';
            else if (avg<40)
                return 'T';
            else
                return 'Z';
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
    cout<<"this runs \n";
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}

    cout<<"this runs \n";
	Student* s = new Student(firstName, lastName, id, scores);
    cout<<"this runs \n";
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}