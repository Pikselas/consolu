#include<iostream>
#include<conio.h>
#include<unistd.h>
using namespace std;
class Fighter
{
	private:
		string FighterParts[4] = {"   \\_/\n",
								 "   #_#\n",
								 "<--<^>-->\n",
								 "  _/ \\_"};
		string fighterLeg1 = "  _/ \\_";
		string fighterLeg2 = " __\\ /__";
		string MainWeapon = "-->";
		string Weapons[3] = {"-->",">>>","<<-+->>"};
		int weaponState = 0;
		int legState = 0;
		int StepedForward = 0;
		int DownedForward = 0;
		int LowestFighterRange = 0;
		int HighestFighterRange = 75;
	public:
		 void Move(int ForwardSteps,int DownwardSteps)
		 {
		 	this->DownedForward += DownwardSteps;
		 	this->StepedForward += ForwardSteps;
		 	 system("cls");
		 	 
			 if(this->legState == 0)
			 	this->FighterParts[3] = this->fighterLeg1;
			 else
			 	this->FighterParts[3] = this->fighterLeg2;
			 this->legState = 1-this->legState;
			 
			 for(int verticalMoved = 0;verticalMoved <= this->DownedForward;verticalMoved += 1)
			 {
			 	cout<<"\n";
			 }
			 int FighterPartsLength = sizeof(FighterParts)/sizeof(FighterParts[0]);
			 for(int i = 0;i<FighterPartsLength;i+=1)
			{
			 for(int crownPos = 0;crownPos <= this->StepedForward;crownPos += 1)
			 {
				cout<<" ";
			 }
			 cout<<this->FighterParts[i];
			}
			if(StepedForward < LowestFighterRange)
			{
				StepedForward = LowestFighterRange;
			}
			else if(StepedForward > HighestFighterRange)
			{
				StepedForward = HighestFighterRange;
			}
			if(DownedForward < 0)
			{
				DownedForward = 0;
			}
			else if(DownedForward > 15)
			{
				DownedForward = 15;
			}
		 }
		 void Fire(int range)
		 {
		 	for(int i = 0;i <= range;i+=1)
		 	{
		 		system("cls");
		 		for(int i  = 0;i<= DownedForward;i+=1)
		 		{
		 		cout<<"\n";
			 	}
			 	for(int i = 0;i<= StepedForward;i+=1)
			 	{
			 		cout<<" ";
				 }
		 		for(int j = 0;j <= i;j+= 1)
		 		{
		 		 cout<<" ";	
				}
				cout<<MainWeapon;
			 }
			 //Move(0,'B');
		 }
		 void ChangeWeapon()
		 {
		 	weaponState += 1;
		 	if(weaponState < (sizeof(Weapons))/sizeof(Weapons[0]))
		 	{
		 		
		    }
			else
			 {
			   weaponState = 0;
			 }
			MainWeapon = Weapons[weaponState];
		 }
		 void Jump()
		 {
		 	Move(1,-1);
		 	sleep(0.1);
		 	Move(1,-1);
		 	sleep(0.1);
		 	Move(1,1);
		 	sleep(0.1);
		 	Move(1,1);
		 }
		 void takeInput()
		 {
		 	int input = getch();
		 	if(input == 119)
		 	{
		 	 this->Move(0,-1);
			}
			else if(input == 115)
			{
				this->Move(0,1);
			}
			else if(input == 100)
			{
				this->Move(1,0);
			}
			else if(input == 97)
			{
				this->Move(-1,0);
			}
			else if(input == 113)
			{
				this->Fire(HighestFighterRange - StepedForward);
			}
			else if(input == 101)
			{
				ChangeWeapon();
			}
			else if(input == 32)
			{
				Jump();
			}
			else
			{
				cout<<input;
			}
		 }
};
//W->119;A->97;S->115;D->100
int main()
{
	Fighter f;
	while(true)
	 f.takeInput();
}
