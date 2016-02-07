#include<iostream>
#include<vector>
#include<conio.h>

using namespace std;

void displayGrid(vector<vector<int>> grid){
		system("cls");
		for(int i=0; i<4;i++){
		for(int j=0; j<4; j++){
			cout << grid[i][j] << "\t";
		}
		cout << endl << endl;
	}
		cout << endl;
		cout << "(W, A, S, D, Q)";
		cout << endl;
}

vector<vector<int>>addNumber(vector<vector<int>> grid){
	int number;
	int locationx;
	int locationy;
	int total = 0;
	bool isSpot = false;
	number = rand() % 11;
	if(number==5)
		number = 4;
	else
		number = 2;

			for(int i=0; i<4;i++){
		for(int j=0; j<4; j++){
			total += grid[i][j];

			}
		}
	if(total==2048)
		return grid;

			for(int i=0; i<4;i++){
		for(int j=0; j<4; j++){
			if(grid[i][j]==0){
				isSpot = true;
				break;
			}
			if(isSpot==true)
				break;
		}
	}
	if(isSpot == false){
		cout << "\nYou lost!\n";
		return grid;
	}
	while(1==1){
		locationx = rand() %4;
		locationy = rand() %4;
		if(grid[locationx][locationy]==0){
			grid[locationx][locationy] = number;
			break;
		}
	}

	return grid;
}
vector<vector<int>>slideUp(vector<vector<int>> grid){
	for(int z = 0; z<5; z++){
	for(int y = 3; y>0; y--){
		for(int x = 3; x>=0; x--){
	if(grid[y-1][x] == 0 && grid[y][x] != 0){
			grid[y-1][x] = grid[y][x];
			grid[y][x] = 0;
}
	else if(grid[y-1][x] != 0 && grid[y][x] !=0 && grid[y][x]==grid[y-1][x]){
		grid[y-1][x] = grid[y-1][x] + grid [y][x];
		grid[y][x] = 0;
	}
	}
	}
	}
	return grid;
}
vector<vector<int>>slideDown(vector<vector<int>> grid){
	for(int z = 0; z<5; z++){
	for(int y = 0; y<3; y++){
		for(int x = 0; x<4; x++){
	if(grid[y+1][x] == 0 && grid[y][x] != 0){
			grid[y+1][x] = grid[y][x];
			grid[y][x] = 0;
}
	else if(grid[y+1][x] != 0 && grid[y][x] !=0 && grid[y][x]==grid[y+1][x]){
		grid[y+1][x] = grid[y+1][x] + grid [y][x];
		grid[y][x] = 0;
	}
	}
	}
	}
	return grid;
}
vector<vector<int>>slideLeft(vector<vector<int>> grid){
	for(int z = 0; z<5; z++){
	for(int y = 3; y>=0; y--){
		for(int x = 3; x>0; x--){
	if(grid[y][x-1] == 0 && grid[y][x] != 0){
			grid[y][x-1] = grid[y][x];
			grid[y][x] = 0;
}
	else if(grid[y][x-1] != 0 && grid[y][x] !=0 && grid[y][x]==grid[y][x-1]){
		grid[y][x-1] = grid[y][x-1] + grid [y][x];
		grid[y][x] = 0;
	}
	}
	}
	}
	return grid;
}
vector<vector<int>>slideRight(vector<vector<int>> grid){
	for(int z = 0; z<5; z++){
	for(int y = 0; y<=3; y++){
		for(int x = 0; x<3; x++){
	if(grid[y][x+1] == 0 && grid[y][x] != 0){
			grid[y][x+1] = grid[y][x];
			grid[y][x] = 0;
}
	else if(grid[y][x+1] != 0 && grid[y][x] !=0 && grid[y][x]==grid[y][x+1]){
		grid[y][x+1] = grid[y][x+1] + grid [y][x];
		grid[y][x] = 0;
	}
	}
	}
	}
	return grid;
}

void turn (vector<vector<int>> grid){
	char option = 0;

	vector<vector<int>> oldGrid = grid;	

	grid = addNumber(grid);

	displayGrid(grid);


	do{
			while(option==0 || option==5){
			option = _getch();
			}	
	switch(option){
	case 'W':
		grid = slideUp(grid);
		break;
	case 'S':
		grid = slideDown(grid);
		break;
	case 'A':
		grid = slideLeft(grid);
		break;
	case 'D':
		grid = slideRight(grid);
		break;
	case 'Q':
		return;
			case 'w':
		grid = slideUp(grid);
		break;
	case 's':
		grid = slideDown(grid);
		break;
	case 'a':
		grid = slideLeft(grid);
		break;
	case 'd':
		grid = slideRight(grid);
		break;
	case 'q':
		return;
	default:
		cout << endl << "Invalid statement, try again: ";
			option = 5;
	}
		}while(option==5);

	if(oldGrid==grid){
		cout << endl << "You lost!" << endl;
		return;
	}
	else
		turn(grid);
}

int main() {

	vector<vector<int> > grid (4, vector<int>(4));
	turn(grid);

	return 0;
}