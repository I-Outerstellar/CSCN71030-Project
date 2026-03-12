#include "SlidingTilesFunctions.hpp"
#include "SlidingTilesData.hpp"

namespace SlidingTilesFunctions {

    bool slide(Board& b, int tile) {
        int tileRow = 0, tileCol = 0;
        int emptyRow = 0, emptyCol = 0;
        bool tileFound = false, emptyFound = false;

        int size = b.board.size(); // size/difficulty of board

        // Find tile and empty space
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (b.access(col, row) == 0) {
                    emptyRow = row;
                    emptyCol = col;
                    emptyFound = true;
                }
                if (b.access(col, row) == tile) {
                    tileRow = row;
                    tileCol = col;
                    tileFound = true;
                }

                // If both are found, exit inner loop 
                if (tileFound && emptyFound) break;
            }

            // If both are found, exit outer loop 
            if (tileFound && emptyFound) break;
        }
        }

        if (!tileFound || !emptyFound) return false;

        // Set false by default
        bool validMove = false;

        // Check if tiles are adjacent
        // If both in the same row and in adjacent columns
        if (tileRow == emptyRow) {
            if (tileCol + 1 == emptyCol || tileCol == emptyCol + 1) validMove = true;
        }
        // If both in the same column and in adjacent rows
        else if (tileCol == emptyCol) {
            if (tileRow + 1 == emptyRow || tileRow == emptyRow + 1) validMove = true;
        }

        if (!validMove) return false; // Invalid swap/slide

        // Swap tile and empty space
        int temp = b.access(tileCol, tileRow);
        b.access(tileCol, tileRow) = b.access(emptyCol, emptyRow);
        b.access(emptyCol, emptyRow) = temp;

        SlidingTilesData::slides++; // Increment the # of slides 
        return true;
    }
}
            