#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <memory>
using namespace std;
using std::hex;
#define WIDTH 15
#define HEIGHT 15
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define VISIT 4

#define LEFT 3
#define RIGHT 1

void initGrid();
int toArr( int x, int y );
int legal( int x, int y );
void Visit( int x, int y );
uint8_t grid[WIDTH*HEIGHT];
uint8_t mouseMap[WIDTH*HEIGHT];
//testing still
uint8_t mouseBinMap[WIDTH*HEIGHT];
// 00 0000 - playerOn? visited? northwall? eastwall? southwall? westwall?

int mouseDir=SOUTH; //idk just need something
int xGoal = -1; int yGoal = -1;
int firstIter = 1;

static int closedMap[WIDTH][HEIGHT]; // visited nodes
static int openMap[WIDTH][HEIGHT]; // unvisited nodes
static int dirs[WIDTH][HEIGHT];

static int dx[4]={0, 1, 0, -1};
static int dy[4]={-1, 0, 1, 0};

class node
{
public:

	int xPos;
	int yPos;
	int level;
	int priority;

	node(int xp, int yp, int d, int p)
	{xPos=xp; yPos=yp; level=d; priority=p;}

	void updatePriority(const int & xDest, const int & yDest)
	{
		priority=level+estimate(xDest, yDest)*10; //A*
	}

	// give better priority to going straight instead of diagonally
	void nextLevel(const int & i) // i: direction
	{
		level+=10;
	}

	// Estimation function for the remaining distance to the goal.
	const int & estimate(const int & xDest, const int & yDest) const
	{
		static int xd, yd, d;
		xd=xDest-xPos;
		yd=yDest-yPos;

		d=static_cast<int>(sqrt(xd*xd+yd*yd));
		return(d);
	}
};

// Determine priority (in the priority queue)
bool operator<(const node & a, const node & b)
{
	return a.priority > b.priority;
}

void turn(int leftOrRight) {
	//TODO
	//need to also have mouse physically turn 90 degrees here
	mouseDir = (mouseDir + leftOrRight) % 4;
}

//get dir opposite of direction
int oppositeDir(int direction) {
	return (direction + 2) % 4;
}

//get left dir of direction
int leftDir(int direction) {
	return (direction + 3) % 4;
}

//get right dir of direction
int rightDir(int direction) {
	return (direction + 1) % 4;
}

//turns until mouse is facing direction
void translateToDir(int direction) {
	while(mouseDir != direction) {
		if ((mouseDir + RIGHT) % 4 == direction) turn(RIGHT);
		else turn(LEFT);
	}
}

char mousePiece() {
	return (mouseDir == NORTH) ? '^' :
		   (mouseDir == EAST) ? '>' :
		   (mouseDir == SOUTH) ? 'v' : '<';
}

// A-star
string pathFind(int &xStart, int &yStart, int &xFinish, int &yFinish)
{
	static priority_queue<node> pq[2]; // unvisited nodes
	static int pqi; // pq index
	static int dirIndex, j, x, y, xdx, ydy;
	static char c;
	pqi=0;

	// reset the node maps
	for(y=0;y<WIDTH+1;y++)
	{
		for(x=0;x<HEIGHT+1;x++)
		{
			closedMap[x][y]=0;
			openMap[x][y]=0;
		}
	}

	// create the start node and push into list of open nodes
	shared_ptr<node> n0 = make_shared<node>(xStart, yStart, 0, 0);
	n0->updatePriority(xFinish, yFinish);
	pq[pqi].push(*n0);
	openMap[xStart][yStart]=n0->priority; // mark it on the open nodes map

	// A* search
	while(!pq[pqi].empty())
	{
		// get the current node w/ the highest priority
		// from the list of open nodes
		n0 = make_shared<node>( pq[pqi].top().xPos, pq[pqi].top().yPos, pq[pqi].top().level, pq[pqi].top().priority);

		x=n0->xPos; y=n0->yPos;

		pq[pqi].pop(); // remove the node from the open list
		openMap[x][y]=0;
		// mark it on the closed nodes map
		closedMap[x][y]=1;

		// quit searching when the goal state is reached
		//if((*n0).estimate(xFinish, yFinish) == 0)
		if(x==xFinish && y==yFinish)
		{
			// generate the path from finish to start
			// by following the directions
			string path="";
			while(!(x==xStart && y==yStart))
			{
				j=dirs[x][y];
				c='0'+(j+4/2)%4;
				path=c+path;
				x+=dx[j];
				y+=dy[j];
			}

			// empty the leftover nodes
			while(!pq[pqi].empty()) pq[pqi].pop();
			return path;
		}

		// generate moves (child nodes) in all possible directions
		for(dirIndex=NORTH;dirIndex<=WEST;dirIndex++) {
			xdx=x+dx[dirIndex]; ydy=y+dy[dirIndex];
			if(!(xdx<0 || xdx>WIDTH-1 || ydy<0 || ydy>HEIGHT-1 ||
					(mouseBinMap[toArr(xdx, ydy)] & (1 << oppositeDir(dirIndex))) || closedMap[xdx][ydy]==1))
			{
				shared_ptr<node> m0 = make_shared<node>( xdx, ydy, n0->level, n0->priority);
				m0->nextLevel(dirIndex);
				m0->updatePriority(xFinish, yFinish);

				// add if not in the open
				if(openMap[xdx][ydy]==0)
				{
					openMap[xdx][ydy]=m0->priority;
					pq[pqi].push(*m0);
					dirs[xdx][ydy]=(dirIndex+4/2)%4;
				}
				else if(openMap[xdx][ydy]>m0->priority)
				{
					// update prio
					openMap[xdx][ydy]=m0->priority;
					dirs[xdx][ydy]=(dirIndex+4/2)%4;

					// replace the node with new node
					while(!(pq[pqi].top().xPos==xdx && pq[pqi].top().yPos==ydy))
					{
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop(); // remove the wanted node

					// empty the larger size pq to the smaller one
					if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
					while(!pq[pqi].empty())
					{
						pq[1-pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi=1-pqi;
					pq[pqi].push(*m0); // add the better node instead
				}
			}
		}
	}
	return "";
}

void initGrid() { for (int i=0; i<(WIDTH+1)*(HEIGHT+1); ++i) grid[i] = 1; }
void initMouseMap() {
	for(int y=0;y<HEIGHT;y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (y==0 || y==HEIGHT-1 || x==0 || x==WIDTH-1) mouseMap[toArr(x, y)] = 1;
			else  mouseMap[toArr(x, y)] = 5;

			if (y==0 || y==HEIGHT-1 || x==0 || x==WIDTH-1) mouseBinMap[toArr(x, y)] = 0b001111;
			else  mouseBinMap[toArr(x, y)] = 0b000000;
		}
	}
}
int toArr(int x, int y) { return y * WIDTH + x; }
int legal(int x, int y) { return !(x < 0 || x >= WIDTH) && !(y < 0 || y >= HEIGHT); }

void mazeGen(int x, int y) {
	grid[toArr(x,y)] = 0;

	int dirs[4] = {NORTH, EAST, SOUTH, WEST};

	for (int i=0; i<4; ++i)
	{
		int r = rand() & 3;
		int temp = dirs[r];
		dirs[r] = dirs[i];
		dirs[i] = temp;
	}
	for (int i=0; i<4; ++i)
	{
		int dx=0, dy=0;
		switch (dirs[i])
		{
			case NORTH: dy = -1; break;
			case SOUTH: dy = 1; break;
			case EAST: dx = 1; break;
			case WEST: dx = -1; break;
		}
		int x2 = x + (dx<<1);
		int y2 = y + (dy<<1);
		if (legal(x2,y2))
		{
			if (grid[toArr(x2,y2)] == 1)
			{
				grid[toArr(x2-dx,y2-dy)] = 0;
				mazeGen(x2,y2);
			}
		}
	}
}

void printMaze(uint8_t maze[], int pX=-1, int pY=-1) {
	for(int y=0;y<HEIGHT;y++)
	{
		for(int x=0;x<WIDTH;x++)
			if(pX==x && pY==y)
				cout<<"\033[1;34m"<<mousePiece()<<"\033[0m";
			else if(maze[toArr(x,y)]==0)
				cout<<".";
			else if(maze[toArr(x,y)]==1)
				cout<<"#"; //obstacle
			else if(maze[toArr(x,y)]==2)
				cout<<"S"; //start
			else if(maze[toArr(x,y)]==3)
				cout<<"*"; //route
			else if(maze[toArr(x,y)]==4)
				cout<<"F"; //finish
			else if(maze[toArr(x, y)]==5)
				cout<<"?"; //unknown
			else if(maze[toArr(x, y)]==6)
				cout<<"\033[1;31mv\033[0m"; //visited
		cout<<endl;
	}
	cout<<endl;
}

void cleanMaze(uint8_t maze[]) {
	for(int y=0;y<HEIGHT;y++) {
		for(int x=0;x<WIDTH;x++) {
			if(maze[toArr(x, y)]==5 || maze[toArr(x, y)]==6 || maze[toArr(x, y)] == 7) maze[toArr(x,y)]=0;
		}
	}
}

void printBinMap() {
	for(int y=0;y<HEIGHT;y++) {
		for(int x=0;x<WIDTH;x++) {
			printf("%01x", mouseBinMap[toArr(x, y)]);
		}
		cout<<endl;
	}
	cout<<endl;
}

//trust me :)
void setWalls(int x, int y, int l, int f, int r) {
	//set current walls
	mouseBinMap[toArr(x, y)] = (((mouseBinMap[toArr(x, y)] |= (l << leftDir(mouseDir))) |= (f << mouseDir)) |= (r << rightDir(mouseDir)));
	//also set same wall for neighbors
	mouseBinMap[toArr(x+dx[leftDir(mouseDir)], y+dy[leftDir(mouseDir)])] |= (l << rightDir(mouseDir));
	mouseBinMap[toArr(x+dx[mouseDir], y+dy[mouseDir])] |= (f << oppositeDir(mouseDir));
	mouseBinMap[toArr(x+dx[rightDir(mouseDir)], y+dy[rightDir(mouseDir)])] |= (r << leftDir(mouseDir));
}

void scanBitNear(int currX, int currY) {
	//TODO
	//instead of updating using grid, we would just update mouse map with each scanners results
	// would instead use scanner input, assign 0 if nothing in next cell (dist > a number) else 1 (dist < a number)

	//left scanner, middle scanner, right scanner
	mouseMap[toArr(currX+dx[leftDir(mouseDir)], currY+dy[leftDir(mouseDir)])] = grid[toArr(currX+dx[leftDir(mouseDir)], currY+dy[leftDir(mouseDir)])];
	mouseMap[toArr(currX+dx[mouseDir], currY+dy[mouseDir])] = grid[toArr(currX+dx[mouseDir], currY+dy[mouseDir])];
	mouseMap[toArr(currX+dx[rightDir(mouseDir)], currY+dy[rightDir(mouseDir)])] = grid[toArr(currX+dx[rightDir(mouseDir)], currY+dy[rightDir(mouseDir)])];

	setWalls(currX, currY,
			(grid[toArr(currX+dx[leftDir(mouseDir)], currY+dy[leftDir(mouseDir)])] == 1),
			(grid[toArr(currX+dx[mouseDir], currY+dy[mouseDir])] == 1),
			(grid[toArr(currX+dx[rightDir(mouseDir)], currY+dy[rightDir(mouseDir)])] == 1)
	);
}

//maybe this will be used one day lol
void calculateGoal() {
	for(int y=0;y<HEIGHT-1;y++) {
		for(int x=0;x<WIDTH-1;x++) {
			//check if there exists a goal loop in the maze
			if (((!(mouseBinMap[toArr(x, y)] & (1 << SOUTH))) && (!(mouseBinMap[toArr(x, y)] & (1 << EAST)))) &&
				((!(mouseBinMap[toArr(x+1, y)] & (1 << WEST))) && (!(mouseBinMap[toArr(x+1, y)] & (1 << SOUTH)))) &&
				((!(mouseBinMap[toArr(x, y+1)] & (1 << EAST))) && (!(mouseBinMap[toArr(x, y+1)] & (1 << NORTH)))) &&
				((!(mouseBinMap[toArr(x+1, y+1)] & (1 << WEST))) && (!(mouseBinMap[toArr(x+1, y+1)] & (1 << NORTH)))))
			{
				xGoal = x;
				yGoal = y;
				cout<<"found goal at ("<<xGoal<<", "<<yGoal<<")"<<endl;
				return;
			}

		}
	}
	cout<<"404 goal not found"<<endl;
}

void moveForward(int x, int y) {
	//TODO

	printMaze(mouseMap, x, y);
//	printBinMap();
	getchar();

	return; //need to physically move mouse 1 cell
}

void flood(int startX, int startY) {
	int currDir = mouseDir;

	//update mouse map with scanners
	scanBitNear(startX, startY);

	// Go forward if cell in front is accessible
	if ((!(mouseBinMap[toArr(startX, startY)] & (1 << currDir))) && (!(mouseBinMap[toArr(startX+dx[currDir], startY+dy[currDir])] & (1 << VISIT)))) {
		//visited
		mouseBinMap[toArr(startX, startY)] |= (1 << VISIT);
		//unimplemented, physically move mouse forward
		moveForward(startX+dx[currDir], startY+dy[currDir]);
		//recurse to the cell ahead
		flood(startX+dx[currDir], startY+dy[currDir]);
	}

	// Go left
	if ((!(mouseBinMap[toArr(startX, startY)] & (1 << leftDir(currDir)))) && (!(mouseBinMap[toArr(startX+dx[leftDir(currDir)], startY+dy[leftDir(currDir)])] & (1 << VISIT)))) {

		//make sure were actually going left, mousedir might have changed
		translateToDir(leftDir(currDir));
		mouseBinMap[toArr(startX, startY)] |= (1 << VISIT);
		moveForward(startX+dx[leftDir(currDir)], startY+dy[leftDir(currDir)]);
		flood(startX+dx[leftDir(currDir)], startY+dy[leftDir(currDir)]);
	}

	// Go right
	if ((!(mouseBinMap[toArr(startX, startY)] & (1 << rightDir(currDir)))) && (!(mouseBinMap[toArr(startX+dx[rightDir(currDir)], startY+dy[rightDir(currDir)])] & (1 << VISIT)))) {
		translateToDir(rightDir(currDir));
		mouseBinMap[toArr(startX, startY)] |= (1 << VISIT);
		moveForward(startX+dx[rightDir(currDir)], startY+dy[rightDir(currDir)]);
		flood(startX+dx[rightDir(currDir)], startY+dy[rightDir(currDir)]);
	}

	translateToDir(oppositeDir(currDir));
	moveForward(startX, startY);
	mouseBinMap[toArr(startX, startY)] |= (1 << VISIT);

	return;
}

vector<int> toInstructs(string& route)
{
	int counter=0;
	char last='x';
	vector<int> instructs;

	int len = route.length() -1;
	for(int i=0; i<= len; i++) {
		if (route[i] == last || last == 'x') {counter++;}
		else if (i != len) {
			instructs.push_back(counter);
			counter=1;
			if ((last=='0' && route[i] == '1') ||
				(last=='1' && route[i] == '2') ||
				(last=='2' && route[i] == '3') ||
				(last=='3' && route[i] == '0')) instructs.push_back(0);
			else if ((last=='0' && route[i] == '3') ||
					(last=='1' && route[i] == '0') ||
					(last=='2' && route[i] == '1') ||
					(last=='3' && route[i] == '2')) instructs.push_back(-1);
		}
		last = route[i];
		if (i == len) instructs.push_back(counter);
	}
	return instructs;
}

int main() {
	srand(time(NULL));

	// create empty map
	initGrid();
	printMaze(grid);

	//create empty mouse map
	initMouseMap();

	// make maze
	mazeGen(1,1);

	// fresh map
	printMaze(grid);

	int xS=1, yS=1;
	int startDir = mouseDir;

	printMaze(mouseMap);

	//flood then clean
	flood(xS, yS);
	translateToDir(startDir);
	cleanMaze(mouseMap);

	//print mouse and mousebin maps, then calculate goal
	printMaze(mouseMap);
	printBinMap();
	calculateGoal();

	if (xGoal == -1 && yGoal == -1){
		xGoal=HEIGHT-2;
		yGoal=WIDTH-2;
	}

	cout<<"starts at ("<<xS<<","<<yS<<')'<<endl;
	cout<<"ends at ("<<xGoal<<","<<yGoal<<')'<<endl;

	//a*
	string route=pathFind(xS, yS, xGoal, yGoal);
	vector<int> instructs = toInstructs(route);

	if(route.length()>0)
	{
		int j;
		int x=xS;
		int y=yS;
		mouseMap[ toArr(x,y) ]=2;

		for(int i=0;i<route.length();i++)
		{
			j = route[i] - 48;
			x=x+dx[j];
			y=y+dy[j];
			mouseMap[toArr(x,y)]=3;
		}

		mouseMap[toArr(x,y)]=4;

		//instructions
		for(int i=0; i<=instructs.size()-1; i++){
			switch (instructs[i]) {
				case -1: cout<<"left turn"<<endl;break;
				case 0: cout<<"right turn"<<endl;break;
				default : cout<<"forward "<<instructs[i]<<endl;break;
			}
		}

		// display the map with the route
		printMaze(mouseMap);
	}
	return(-1);
}