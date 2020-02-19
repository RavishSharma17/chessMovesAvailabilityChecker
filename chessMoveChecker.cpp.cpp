#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>
using namespace std; 

vector< vector< int > > arrayOfPossibleKingMoves(){
  // 2d vector for x and y movements.
  vector< vector< int > > kingMovementMatrix{ { -1, -1, 0, 1, 1, 1, 0, -1 },
                                              { 0, 1, 1, 1, 0, -1, -1, -1 } };

  return kingMovementMatrix;
}

vector< vector< int > > arrayOfPossibleQueenMoves(){
  // 2d vector for x and y movements.
  vector< vector< int > > queenMovementMatrix{ { -1, -2, -3, -4, -5, -6, -7, -1, -2, -3, -4, -5, -6, -7, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -4, -5, -6, -7 },
                                               { 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -4, -5, -6, -7, -1, -2, -3, -4, -5, -6, -7, -1, -2, -3, -4, -5, -6, -7 } };

  return queenMovementMatrix;
}

vector< vector< int > > arrayOfPossibleBishopMoves(){
  // 2d vector for x and y movements.
  vector< vector< int > > bishopMovementMatrix{ { -1, -2, -3, -4, -5, -6, -7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -4, -5, -6, -7 },
                                                { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -4, -5, -6, -7, -1, -2, -3, -4, -5, -6, -7 } };

  return bishopMovementMatrix;
}
  
vector< vector< int > > arrayOfPossibleHorseMoves(){
  // 2d vector for x and y movements.
  vector< vector< int > > horseMovementMatrix{ { -2, -1, 1, 2, 2, 1, -1, -2 },
                                               { 1, 2, 2, 1, -1, -2, -2, -1 } };

  return horseMovementMatrix;
}

vector< vector< int > > arrayOfPossibleRookMoves(){
  // 2d vector for x and y movements.
  vector< vector< int > > rookMovementMatrix{ { -1, -2, -3, -4, -5, -6, -7, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0 },
                                              { 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3, -4, -5, -6, -7 } };

  return rookMovementMatrix;
}

vector< vector< int > > arrayOfPossiblePawnMoves(){
  // 2d vector for x and y movements.
  vector< vector< int > > pawnMovementMatrix{ { -1 },
                                              { 0 } };

  return pawnMovementMatrix;
}
  
vector< string > findPossibleMoves( vector< vector< string > > &chessMat, string pieceName , int pieceRowPosition, int pieceColumnPosition ) 
{ 
  vector< vector< int > > givenPieceMatrix;
    
  if( "KING" == pieceName ){
    givenPieceMatrix = arrayOfPossibleKingMoves();
  }
  else if( "QUEEN" == pieceName ){
    givenPieceMatrix = arrayOfPossibleQueenMoves();
  }
  else if( "BISHOP" == pieceName ){
    givenPieceMatrix = arrayOfPossibleBishopMoves();
  }
  else if( "HORSE" == pieceName ){
    givenPieceMatrix = arrayOfPossibleHorseMoves();
  }
  else if( "ROOK" == pieceName ){
    givenPieceMatrix = arrayOfPossibleRookMoves();
  }
  else{
    givenPieceMatrix = arrayOfPossiblePawnMoves();
  }
  
    vector< string > possibleMoves;
  
    // Check if each possible move is valid or not 
    for( int i = 0; i < givenPieceMatrix[ 0 ].size(); i++ ){
        // Position of knight after move 
        int x = pieceRowPosition + givenPieceMatrix[ 0 ][ i ]; 
        int y = pieceColumnPosition + givenPieceMatrix[ 1 ][ i ];
  
        // count valid moves within the boundaries of the chess mat
        if ( x >= 0 && y >= 0 && x < 8 && y < 8 ) 
            possibleMoves.push_back( chessMat[ x ][ y ] );
    } 

    return possibleMoves; 
} 

bool checkForValidPieceName( string pieceName ){
  return ( "KING" == pieceName || "QUEEN" == pieceName || "BISHOP" == pieceName
        || "HORSE" == pieceName || "ROOK" == pieceName || "PAWN" == pieceName );
}

bool checkForValidPiecePosition( vector< vector< string > > &chessMat, string piecePosition ){
  
    vector< vector< string > >::iterator row;

    for ( row = chessMat.begin(); row != chessMat.end(); row++ ) {
        if( find( row->begin(), row->end(), piecePosition ) != row->end() )
            return true;
    }

    return false;
}

int main() 
{ 
    vector< vector< string > > chessMat{ { "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8" }, 
                                         { "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8" }, 
                                         { "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8" },
                                         { "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8" }, 
                                         { "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8" }, 
                                         { "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8" }, 
                                         { "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8" }, 
                                         { "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8" } }; 
  
    string pieceName, piecePosition;
    cin >> pieceName >> piecePosition;
    transform( pieceName.begin(), pieceName.end(), pieceName.begin(), ::toupper );
    transform( piecePosition.begin(), piecePosition.end(), piecePosition.begin(), ::toupper );
  
    bool validPieceName = checkForValidPieceName( pieceName );
    bool validPiecePosition = checkForValidPiecePosition( chessMat, piecePosition );
  
    if( validPieceName ){
      if( validPiecePosition ){
        int pieceRowPosition = 0;
        int pieceColumnPosition = 0;
        bool positionFoundOnMat = false;

        for ( int i = 0; i < 8; i++ ) {
          for( int j = 0; j < 8; j++ ){
            if( piecePosition == chessMat[ i ][ j ] ){
                pieceRowPosition = i;
                pieceColumnPosition = j;
                positionFoundOnMat = true;
                break;
              } 
          }
          if( positionFoundOnMat ){
            break;  
          }
        }
        
        vector< string > outputPossibleMoves = findPossibleMoves( chessMat, pieceName, pieceRowPosition, pieceColumnPosition ); 
      
      if( !outputPossibleMoves.empty() )
      {
        for ( int i = 0; i < outputPossibleMoves.size(); i++ ) 
            cout << outputPossibleMoves[ i ] << " ";  
      }
      else
      {
        cout << "No possible moves available";  
      }
      
      } 
      else 
      {
        cout << "Please try again with a valid chess piece position";
      }
    } 
    else 
    {
      cout << "Please try again with a valid chess piece name"; 
    }
  
    return 0; 
} 