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


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
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

}

namespace IntegrationTests {
	

	TEST_CLASS(ContinueGame) {
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
			Assert::AreEqual(208u, scores.at(0));
			Assert::AreEqual(220u, scores.at(1));
			Assert::AreEqual(243u, scores.at(2));
		}
	};
}