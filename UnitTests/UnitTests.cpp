#include "CppUnitTest.h"
#include <fstream>
#include "../Project II Slider Game/Board.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"
#include "../Project II Slider Game/SlidingTilesEnums.hpp"
#include "../Project II Slider Game/SlidingTilesFunctionsHelpers.hpp"
#include "../Project II Slider Game/UserFunctionsHelpers.hpp"
#include "SlidingTilesFunctionsMock.hpp"
#include "UserFunctionsHelpersMock.hpp"
#include "BoardMock.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
	namespace BoardClassTests {
		TEST_CLASS(BoardConstructors) {
		private:

		public:
			TEST_METHOD(DefaultConstructor) {
				BoardMock board;
				size_t expected = 0;
				size_t actual = board.accessBoard().size();

				Assert::AreEqual(expected, actual);
			}

			TEST_METHOD(ParameterizedConstructor_EASY) {
				BoardMock board(SlidingTilesEnums::Difficulty::EASY);
				size_t expectedSize = 3;
				size_t actualSize = board.accessBoard().size();

				Assert::AreEqual(expectedSize, actualSize);

				for (int i = 0; i < expectedSize; i++) {
					actualSize = board.accessBoard().at(i).size();
					Assert::AreEqual(expectedSize, actualSize);

					for (int j = 0; j < expectedSize; j++) {
						size_t expectedNumber = i * expectedSize + j + 1;
						size_t actualNumber = board.accessBoard().at(i).at(j);
						Assert::AreEqual(expectedNumber, actualNumber);
					}
				}
			}

			TEST_METHOD(ParameterizedConstructor_MEDIUM) {
				BoardMock board(SlidingTilesEnums::Difficulty::MEDIUM);
				size_t expectedSize = 4;
				size_t actualSize = board.accessBoard().size();

				Assert::AreEqual(expectedSize, actualSize);

				for (int i = 0; i < expectedSize; i++) {
					actualSize = board.accessBoard().at(i).size();
					Assert::AreEqual(expectedSize, actualSize);

					for (int j = 0; j < expectedSize; j++) {
						size_t expectedNumber = i * expectedSize + j + 1;
						size_t actualNumber = board.accessBoard().at(i).at(j);
						Assert::AreEqual(expectedNumber, actualNumber);
					}
				}
			}

			TEST_METHOD(ParameterizedConstructor_HARD) {
				BoardMock board(SlidingTilesEnums::Difficulty::HARD);
				size_t expectedSize = 6;
				size_t actualSize = board.accessBoard().size();

				Assert::AreEqual(expectedSize, actualSize);

				for (int i = 0; i < expectedSize; i++) {
					actualSize = board.accessBoard().at(i).size();
					Assert::AreEqual(expectedSize, actualSize);

					for (int j = 0; j < expectedSize; j++) {
						size_t expectedNumber = i * expectedSize + j + 1;
						size_t actualNumber = board.accessBoard().at(i).at(j);
						Assert::AreEqual(expectedNumber, actualNumber);
					}
				}
			}

			TEST_METHOD(ParameterizedConstructor_INSANE) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);
				size_t expectedSize = 9;
				size_t actualSize = board.accessBoard().size();

				Assert::AreEqual(expectedSize, actualSize);

				for (int i = 0; i < expectedSize; i++) {
					actualSize = board.accessBoard().at(i).size();
					Assert::AreEqual(expectedSize, actualSize);

					for (int j = 0; j < expectedSize; j++) {
						size_t expectedNumber = i * expectedSize + j + 1;
						size_t actualNumber = board.accessBoard().at(i).at(j);
						Assert::AreEqual(expectedNumber, actualNumber);
					}
				}
			}
		};

		TEST_CLASS(BoardCanAccess) {
		private:

		public:
			TEST_METHOD(TrueForRows) {
				BoardMock board(SlidingTilesEnums::Difficulty::EASY);
				int size = 3;

				for (int i = 0; i < size; i++) {
					Assert::IsTrue(board.canAccess(i));
				}
			}

			TEST_METHOD(TrueForRowsAndColumns) {
				BoardMock board(SlidingTilesEnums::Difficulty::EASY);
				int size = 3;

				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						Assert::IsTrue(board.canAccess(i, j));
					}
				}
			}

			TEST_METHOD(FalseForRows) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);

				Assert::IsFalse(board.canAccess(10));
			}

			TEST_METHOD(FalseForRowIndex) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);

				Assert::IsFalse(board.canAccess(10, 0));
			}

			TEST_METHOD(FalseForColumnIndex) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);

				Assert::IsFalse(board.canAccess(0, 10));
			}

			TEST_METHOD(FalseForRowsAndColumnIndex) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);

				Assert::IsFalse(board.canAccess(10, 10));
			}
		};

		TEST_CLASS(BoardAccess) {
		private:

		public:
			TEST_METHOD(AccessesRows) {
				BoardMock board(SlidingTilesEnums::Difficulty::EASY);
				int size = 3;

				std::vector<size_t> expected1{ 1, 2, 3 };
				std::vector<size_t> expected2{ 4, 5, 6 };
				std::vector<size_t> expected3{ 7, 8, 9 };
				std::vector<size_t> actual1 = board.access(0);
				std::vector<size_t> actual2 = board.access(1);
				std::vector<size_t> actual3 = board.access(2);

				for (int i = 0; i < size; i++) {
					Assert::AreEqual(expected1.at(i), actual1.at(i));
					Assert::AreEqual(expected2.at(i), actual2.at(i));
					Assert::AreEqual(expected3.at(i), actual3.at(i));
				}
			}

			TEST_METHOD(AccessIndexes) {
				BoardMock board(SlidingTilesEnums::Difficulty::MEDIUM);
				int size = 4;

				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						size_t expectedNumber = i * size + j + 1;
						size_t actualNumber = board.access(i, j);
						Assert::AreEqual(expectedNumber, actualNumber);
					}
				}
			}

			TEST_METHOD(AccessRowThrows) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);
				Assert::ExpectException<std::out_of_range>([&]() {
					board.access(10);
					}
				);
			}

			TEST_METHOD(AccessRowIndexThrows) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);
				Assert::ExpectException<std::out_of_range>([&]() {
					board.access(10, 0);
					}
				);
			}

			TEST_METHOD(AccessColumnIndexThrows) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);
				Assert::ExpectException<std::out_of_range>([&]() {
					board.access(0, 10);
					}
				);
			}

			TEST_METHOD(AccessRowAndColumnIndexThrows) {
				BoardMock board(SlidingTilesEnums::Difficulty::INSANE);
				Assert::ExpectException<std::out_of_range>([&]() {
					board.access(10, 10);
					}
				);
			}
		};

		TEST_CLASS(IsRowEmpty) {
			TEST_METHOD(False) {
				BoardMock board(SlidingTilesEnums::Difficulty::EASY);
				Assert::IsFalse(board.hasEmptyRow());
			}

			TEST_METHOD(True_RowEmpty) {
				BoardMock board(SlidingTilesEnums::Difficulty::EASY);
				board.accessBoard().push_back(std::vector<size_t>());
				Assert::IsTrue(board.hasEmptyRow());
			}

			TEST_METHOD(True_BoardEmpty) {
				BoardMock board;
				Assert::IsTrue(board.hasEmptyRow());
			}
		};
	}

	namespace SlidingTilesFunctionsHelpersTests {
		TEST_CLASS(GetOppositeDirection) {
		private:

		public:
			TEST_METHOD(OppositeOfUp) {
				SlidingTilesEnums::Direction expected = SlidingTilesEnums::Direction::DOWN;
				SlidingTilesEnums::Direction actual = SlidingTilesFunctionsHelpers::getOpposite(SlidingTilesEnums::Direction::UP);
				Assert::AreEqual(static_cast<int>(expected), static_cast<int>(actual));
			}

			TEST_METHOD(OppositeOfDown) {
				SlidingTilesEnums::Direction expected = SlidingTilesEnums::Direction::UP;
				SlidingTilesEnums::Direction actual = SlidingTilesFunctionsHelpers::getOpposite(SlidingTilesEnums::Direction::DOWN);
				Assert::AreEqual(static_cast<int>(expected), static_cast<int>(actual));
			}

			TEST_METHOD(OppositeOfLeft) {
				SlidingTilesEnums::Direction expected = SlidingTilesEnums::Direction::RIGHT;
				SlidingTilesEnums::Direction actual = SlidingTilesFunctionsHelpers::getOpposite(SlidingTilesEnums::Direction::LEFT);
				Assert::AreEqual(static_cast<int>(expected), static_cast<int>(actual));
			}

			TEST_METHOD(OppositeOfRight) {
				SlidingTilesEnums::Direction expected = SlidingTilesEnums::Direction::LEFT;
				SlidingTilesEnums::Direction actual = SlidingTilesFunctionsHelpers::getOpposite(SlidingTilesEnums::Direction::RIGHT);
				Assert::AreEqual(static_cast<int>(expected), static_cast<int>(actual));
			}
		};
	}

	namespace SlidingTilesFunctionsTests {
		TEST_CLASS(StartGame) {
		private:

		public:
			TEST_METHOD(EasyDifficulty) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
				size_t expectedSize = 3;

				Assert::AreEqual(expectedSize, SlidingTilesData::boardSize);
				Assert::AreEqual(expectedSize - 1, SlidingTilesData::currentColumn);
				Assert::AreEqual(SlidingTilesData::currentRow, SlidingTilesData::currentColumn);
				Assert::AreEqual(static_cast<unsigned int>(0), SlidingTilesData::slides);

				for (size_t i = 0; i < expectedSize; i++) {
					for (size_t j = 0; j < expectedSize; j++) {
						Assert::AreEqual(SlidingTilesData::board.access(i, j), i * expectedSize + j + 1);
					}
				}
			}

			TEST_METHOD(MediumDifficulty) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::MEDIUM);
				size_t expectedSize = 4;

				Assert::AreEqual(expectedSize, SlidingTilesData::boardSize);
				Assert::AreEqual(expectedSize - 1, SlidingTilesData::currentColumn);
				Assert::AreEqual(SlidingTilesData::currentRow, SlidingTilesData::currentColumn);
				Assert::AreEqual(static_cast<unsigned int>(0), SlidingTilesData::slides);

				for (size_t i = 0; i < expectedSize; i++) {
					for (size_t j = 0; j < expectedSize; j++) {
						Assert::AreEqual(SlidingTilesData::board.access(i, j), i * expectedSize + j + 1);
					}
				}
			}

			TEST_METHOD(HardDifficulty) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				size_t expectedSize = 6;

				Assert::AreEqual(expectedSize, SlidingTilesData::boardSize);
				Assert::AreEqual(expectedSize - 1, SlidingTilesData::currentColumn);
				Assert::AreEqual(SlidingTilesData::currentRow, SlidingTilesData::currentColumn);
				Assert::AreEqual(static_cast<unsigned int>(0), SlidingTilesData::slides);

				for (size_t i = 0; i < expectedSize; i++) {
					for (size_t j = 0; j < expectedSize; j++) {
						Assert::AreEqual(SlidingTilesData::board.access(i, j), i * expectedSize + j + 1);
					}
				}
			}

			TEST_METHOD(InsaneDifficulty) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::INSANE);
				size_t expectedSize = 9;

				Assert::AreEqual(expectedSize, SlidingTilesData::boardSize);
				Assert::AreEqual(expectedSize - 1, SlidingTilesData::currentColumn);
				Assert::AreEqual(SlidingTilesData::currentRow, SlidingTilesData::currentColumn);
				Assert::AreEqual(static_cast<unsigned int>(0), SlidingTilesData::slides);

				for (size_t i = 0; i < expectedSize; i++) {
					for (size_t j = 0; j < expectedSize; j++) {
						Assert::AreEqual(SlidingTilesData::board.access(i, j), i * expectedSize + j + 1);
					}
				}
			}
		};

		TEST_CLASS(Slide) {
		private:

		public:

			TEST_METHOD(UpDirection) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);

				bool passed1 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				bool passed2 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				bool passed3 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);

				Assert::IsTrue(passed1);
				Assert::IsTrue(passed2);
				Assert::IsFalse(passed3);

				Assert::AreEqual(static_cast<size_t>(9), SlidingTilesData::board.access(0, 2));
				Assert::AreEqual(static_cast<size_t>(3), SlidingTilesData::board.access(1, 2));
				Assert::AreEqual(static_cast<size_t>(6), SlidingTilesData::board.access(2, 2));
			}

			TEST_METHOD(LeftDirection) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);

				bool passed1 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::LEFT);
				bool passed2 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::LEFT);
				bool passed3 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::LEFT);

				Assert::IsTrue(passed1);
				Assert::IsTrue(passed2);
				Assert::IsFalse(passed3);

				Assert::AreEqual(static_cast<size_t>(9), SlidingTilesData::board.access(2, 0));
				Assert::AreEqual(static_cast<size_t>(7), SlidingTilesData::board.access(2, 1));
				Assert::AreEqual(static_cast<size_t>(8), SlidingTilesData::board.access(2, 2));
			}

			TEST_METHOD(RightDirection) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
				SlidingTilesData::currentColumn = SlidingTilesData::currentRow = 0; //Under normal circumstances would be a bug

				bool passed1 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::RIGHT);
				bool passed2 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::RIGHT);
				bool passed3 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::RIGHT);

				Assert::IsTrue(passed1);
				Assert::IsTrue(passed2);
				Assert::IsFalse(passed3);

				Assert::AreEqual(static_cast<size_t>(2), SlidingTilesData::board.access(0, 0));
				Assert::AreEqual(static_cast<size_t>(3), SlidingTilesData::board.access(0, 1));
				Assert::AreEqual(static_cast<size_t>(1), SlidingTilesData::board.access(0, 2));
			}

			TEST_METHOD(DownDirection) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
				SlidingTilesData::currentColumn = SlidingTilesData::currentRow = 0; //Under normal circumstances would be a bug

				bool passed1 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::DOWN);
				bool passed2 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::DOWN);
				bool passed3 = SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::DOWN);

				Assert::IsTrue(passed1);
				Assert::IsTrue(passed2);
				Assert::IsFalse(passed3);

				Assert::AreEqual(static_cast<size_t>(4), SlidingTilesData::board.access(0, 0));
				Assert::AreEqual(static_cast<size_t>(7), SlidingTilesData::board.access(1, 0));
				Assert::AreEqual(static_cast<size_t>(1), SlidingTilesData::board.access(2, 0));
			}
		};

		TEST_CLASS(IsBoardOrdered) {
		private:

		public:

			TEST_METHOD(EasyTrue) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
				Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(EasyFalseViaSliding) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(EasyFalseViaShuffle) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::EASY);
				SlidingTilesFunctions::shuffle();
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(MediumTrue) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::MEDIUM);
				Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(MediumFalseViaSliding) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::MEDIUM);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(MediumFalseViaShuffle) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::MEDIUM);
				SlidingTilesFunctions::shuffle();
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(HardTrue) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(HardFalseViaSliding) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(HardFalseViaShuffle) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				SlidingTilesFunctions::shuffle();
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(InsaneTrue) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::INSANE);
				Assert::IsTrue(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(InsaneFalseViaSliding) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::INSANE);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}

			TEST_METHOD(InsaneFalseViaShuffle) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::INSANE);
				SlidingTilesFunctions::shuffle();
				Assert::IsFalse(SlidingTilesFunctions::isBoardOrdered());
			}
		};

		TEST_CLASS(LoadScores) {
		public:

			TEST_METHOD(FileDoesNotExist) {
				auto scores = SlidingTilesFunctionsMock::loadScores("nonexistent_file.txt");
				Assert::AreEqual(static_cast<size_t>(0), scores.size());
			}

			TEST_METHOD(EmptyFile) {
				std::ofstream("empty.txt"); // create empty file
				auto scores = SlidingTilesFunctionsMock::loadScores("empty.txt");
				Assert::AreEqual(static_cast<size_t>(0), scores.size());
			}

			TEST_METHOD(SingleScore) {
				std::ofstream out("single.txt");
				out << 42;
				out.close();

				auto scores = SlidingTilesFunctionsMock::loadScores("single.txt");
				Assert::AreEqual(static_cast<size_t>(1), scores.size());
				Assert::AreEqual(42u, scores[0]);
			}

			TEST_METHOD(MultipleScoresUnsorted) {
				std::ofstream out("unsorted.txt");
				out << "50\n10\n30\n";
				out.close();

				auto scores = SlidingTilesFunctionsMock::loadScores("unsorted.txt");
				Assert::AreEqual(static_cast<size_t>(3), scores.size());
				Assert::AreEqual(10u, scores[0]);
				Assert::AreEqual(30u, scores[1]);
				Assert::AreEqual(50u, scores[2]);
			}

			TEST_METHOD(AlreadySortedInput) {
				std::ofstream out("sorted.txt");
				out << "1\n2\n3\n4\n5\n";
				out.close();

				auto scores = SlidingTilesFunctionsMock::loadScores("sorted.txt");
				Assert::AreEqual(static_cast<size_t>(5), scores.size());
				for (size_t i = 0; i < scores.size(); i++)
					Assert::AreEqual(static_cast<unsigned int>(i + 1), scores[i]);
			}

			TEST_METHOD(DuplicateScores) {
				std::ofstream out("duplicates.txt");
				out << "5\n3\n5\n3\n";
				out.close();

				auto scores = SlidingTilesFunctionsMock::loadScores("duplicates.txt");
				Assert::AreEqual(static_cast<size_t>(4), scores.size());
				Assert::AreEqual(3u, scores[0]);
				Assert::AreEqual(3u, scores[1]);
				Assert::AreEqual(5u, scores[2]);
				Assert::AreEqual(5u, scores[3]);
			}

			TEST_METHOD(ExactlyTop10Scores) {
				std::ofstream out("top10.txt");
				for (unsigned int i = 10; i >= 1; i--)
					out << i << "\n";
				out.close();

				auto scores = SlidingTilesFunctionsMock::loadScores("top10.txt");
				Assert::AreEqual(static_cast<size_t>(10), scores.size());
				for (size_t i = 0; i < 10; i++)
					Assert::AreEqual(static_cast<unsigned int>(i + 1), scores[i]);
			}

			TEST_METHOD(MoreThanTop10Scores) {
				std::ofstream out("morethan10.txt");
				for (unsigned int i = 15; i >= 1; i--)
					out << i << "\n";
				out.close();

				auto scores = SlidingTilesFunctionsMock::loadScores("morethan10.txt");
				Assert::AreEqual(static_cast<size_t>(SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE), scores.size());
				for (size_t i = 0; i < SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE; i++)
					Assert::AreEqual(static_cast<unsigned int>(i + 1), scores[i]);
			}

			TEST_METHOD(DifferentDifficultyFiles) {
				std::ofstream outEasy("easy_test.txt");
				std::ofstream outHard("hard_test.txt");

				outEasy << "5\n2\n9\n";
				outHard << "20\n15\n25\n";
				outEasy.close();
				outHard.close();

				auto easyScores = SlidingTilesFunctionsMock::loadScores("easy_test.txt");
				auto hardScores = SlidingTilesFunctionsMock::loadScores("hard_test.txt");

				Assert::AreEqual(static_cast<size_t>(3), easyScores.size());
				Assert::AreEqual(2u, easyScores[0]);
				Assert::AreEqual(5u, easyScores[1]);
				Assert::AreEqual(9u, easyScores[2]);

				Assert::AreEqual(static_cast<size_t>(3), hardScores.size());
				Assert::AreEqual(15u, hardScores[0]);
				Assert::AreEqual(20u, hardScores[1]);
				Assert::AreEqual(25u, hardScores[2]);
			}
		};

		TEST_CLASS(WriteScores) {
		public:

			TEST_METHOD(WritesSingleScore) {
				std::string file = "write_single.txt";
				std::ofstream(file, std::ios::trunc).close();

				SlidingTilesData::slides = 42;
				SlidingTilesFunctionsMock::writeScore(file);

				std::ifstream in(file);
				int value = -1;
				in >> value;

				Assert::AreEqual(42, value);
			}

			TEST_METHOD(AppendsScores) {
				std::string file = "write_append.txt";
				std::ofstream(file, std::ios::trunc).close();

				SlidingTilesData::slides = 10;
				SlidingTilesFunctionsMock::writeScore(file);

				SlidingTilesData::slides = 20;
				SlidingTilesFunctionsMock::writeScore(file);

				SlidingTilesData::slides = 30;
				SlidingTilesFunctionsMock::writeScore(file);

				SlidingTilesData::slides = 40;
				SlidingTilesFunctionsMock::writeScore(file);

				std::ifstream in(file);

				int a = -1, b = -1, c = -1, d = -1;
				in >> a >> b >> c >> d;

				Assert::AreEqual(10, a);
				Assert::AreEqual(20, b);
				Assert::AreEqual(30, c);
				Assert::AreEqual(40, d);
			}

			TEST_METHOD(WriteDifferentFiles) {
				std::string file1 = "write_file1.txt";
				std::string file2 = "write_file2.txt";

				std::ofstream(file1, std::ios::trunc).close();
				std::ofstream(file2, std::ios::trunc).close();

				SlidingTilesData::slides = 99;
				SlidingTilesFunctionsMock::writeScore(file1);

				SlidingTilesData::slides = 55;
				SlidingTilesFunctionsMock::writeScore(file2);

				std::ifstream in1(file1);
				std::ifstream in2(file2);

				int v1 = -1, v2 = -1;
				in1 >> v1;
				in2 >> v2;

				Assert::AreEqual(99, v1);
				Assert::AreEqual(55, v2);
			}
		};
	}
}

namespace IntegrationTests {
	namespace UserFunctionsHelpersTests {
		TEST_CLASS(TrySlide) {
		private:

		public:
			TEST_METHOD(SlidesIncrease) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::UP);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::LEFT);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::UP);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::UP);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::LEFT);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::DOWN);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::RIGHT);

				unsigned int expected = 7;
				Assert::AreEqual(expected, SlidingTilesData::slides);
			}

			TEST_METHOD(SlidesDoNotIncrease) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::DOWN);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::RIGHT);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::DOWN);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::RIGHT);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::RIGHT);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::DOWN);

				unsigned int expected = 0;
				Assert::AreEqual(expected, SlidingTilesData::slides);
			}

			TEST_METHOD(SlidesIncreaseAndDoNotIncrease) {
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::DOWN); //Fails
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::UP); //Succeeds
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::LEFT); //Succeeds
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::RIGHT); //Succeeds
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::RIGHT); //Fails
				UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::DOWN); //Succeeds

				unsigned int expected = 4;
				Assert::AreEqual(expected, SlidingTilesData::slides);
			}
		};

		TEST_CLASS(ContinueGame) {
		private:

		public:
			TEST_METHOD(BoardUnordered_FirstReturn) {
				const char* fileName = "continue_game_no_successes_path_1.txt";
				std::remove(fileName);
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);

				bool success = UserFunctionsHelpersMock::continueGame(fileName);

				Assert::IsTrue(success);
				Assert::AreEqual(static_cast<size_t>(30), SlidingTilesData::board.access(5, 5));

				std::vector<unsigned int> scores = SlidingTilesFunctionsMock::loadScores(fileName);

				Assert::AreEqual(static_cast<size_t>(0), scores.size());
			}

			TEST_METHOD(BoardUnordered_SecondReturn) {
				const char* fileName = "continue_game_no_successes_path_2.txt";
				std::remove(fileName);
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::UP);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::LEFT);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::DOWN);
				SlidingTilesFunctions::slide(SlidingTilesEnums::Direction::RIGHT);

				bool success = UserFunctionsHelpersMock::continueGame(fileName);

				Assert::IsTrue(success);
				Assert::AreEqual(static_cast<size_t>(36), SlidingTilesData::board.access(5, 5));

				std::vector<unsigned int> scores = SlidingTilesFunctionsMock::loadScores(fileName);

				Assert::AreEqual(static_cast<size_t>(0), scores.size());
			}

			TEST_METHOD(BoardOrdered) {
				const char* fileName = "continue_game_successes.txt";
				std::remove(fileName);
				SlidingTilesFunctions::startGame(SlidingTilesEnums::Difficulty::HARD);

				SlidingTilesData::slides = 243;
				bool success1 = UserFunctionsHelpersMock::continueGame(fileName);

				SlidingTilesData::slides = 208;
				bool success2 = UserFunctionsHelpersMock::continueGame(fileName);

				for (int i = 0; i < 3; i++) {
					UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::UP);
					UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::LEFT);
					UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::DOWN);
					UserFunctionsHelpersMock::trySlide(SlidingTilesEnums::Direction::RIGHT);
				}
				bool success3 = UserFunctionsHelpersMock::continueGame(fileName); //Slide count after is 220

				Assert::IsFalse(success1);
				Assert::IsFalse(success2);
				Assert::IsFalse(success3);

				std::vector<unsigned int> scores = SlidingTilesFunctionsMock::loadScores(fileName);
				Assert::AreEqual(static_cast<size_t>(3), scores.size());
				Assert::AreEqual(208u, scores.at(0));
				Assert::AreEqual(220u, scores.at(1));
				Assert::AreEqual(243u, scores.at(2));
			}
		};
	}
}