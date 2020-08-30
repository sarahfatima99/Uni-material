#include <bits/stdc++.h>
using namespace std;

#define DIMENSIONS 10
typedef unsigned long long ull;

bool buffer[DIMENSIONS][DIMENSIONS];
bool visited[DIMENSIONS][DIMENSIONS]{false};
ull counter = 0u, rows, cols;

// Coord class, for containing the coordinate tuple
struct Coord
{
    // since coord values are always positve, let size_t be their data type
    ull X, Y;

    // To initialize the Coord object
    Coord(ull X = 0, ull Y = 0)
        : X(X), Y(Y) {}

    // Simplifying code by abstracting away the equality - checks if both are equal
    bool operator==(const Coord &rhs)
    {
        return this->X == rhs.X - 1 && this->Y == rhs.Y - 1;
    }
};

bool isSafe(int x, int y) {
    return ( x < rows && y < cols && buffer[x][y] == 0);
}

void countPaths(ull x, ull y, ull rowEnd, ull colEnd) {

    queue<Coord> q;
    q.push(Coord{x, y});

    while ( !q.empty() ) {
        Coord temp = q.front();
        visited[temp.X][temp.Y] = false;
        q.pop();

        if ( temp == Coord{rowEnd, colEnd} )
            ::counter++;

        // std::cout << "( " << temp.X + 1 << ", " << temp.Y << " )" << " " << isSafe(temp.X + 1, temp.Y) << " " << !visited[temp.X + 1][temp.Y] << "\n";
        if ( isSafe(temp.X + 1, temp.Y) && !visited[temp.X + 1][temp.Y]) {
            // std::cout << "In vertical: ";
            // std::cout << "( " << temp.X + 1 << ", " << temp.Y << " )" << "\n";
            visited[temp.X + 1][temp.Y] = true;
            q.push(Coord{temp.X + 1, temp.Y});
        }

        // std::cout << "( " << temp.X << ", " << temp.Y + 1 << " )" << " " << isSafe(temp.X, temp.Y + 1) << " " << !visited[temp.X][temp.Y + 1] << "\n";
        if ( isSafe(temp.X, temp.Y + 1) && !visited[temp.X][temp.Y + 1]) {
            // std::cout << "In horizontal: ";
            // std::cout << "( " << temp.X << ", " << temp.Y + 1 << " )" << "\n";
            visited[temp.X][temp.Y + 1] = true;
            q.push(Coord{temp.X, temp.Y + 1});            
        }
    }
}

int main(void) {

    ifstream inFile("in.txt");
    
    // string object to take in the values for the board
    string temp;                        

    inFile >> rows >> cols;

    // ... put input file pointer to start of the board ...
    inFile.seekg(4);

    // ... and then, for each row of the board ...
    for (int i = 0; i < rows; ++i)
    {
        // ... extract the line as a string ...
        getline(inFile, temp);

        // ... foreach char of the extracted string ... 
        for (int j = 0; j < temp.size(); ++j) 

            // ... get whether it is a 0 or 1 in its place ...
            buffer[i][j] = temp[j] - '0';
    }

    // for ( int i = 0; i < rows ; ++i ) {
    //     for ( int j = 0; j < cols ; ++j )  {
    //         std::cout << buffer[i][j];
    //     }
    //     std::cout << "\n";
    // }

    countPaths(0, 0, rows, cols);
    if ( ::counter == 0 ) std::cout << "No path.\n";
    else std::cout << "\nCounter: " << ::counter << "\n";

    return 0;
}
