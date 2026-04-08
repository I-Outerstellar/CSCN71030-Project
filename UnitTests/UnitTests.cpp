#include "CppUnitTest.h"
#include <fstream>
#include "../Project II Slider Game/Board.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"
#include "../Project II Slider Game/SlidingTilesEnums.hpp"
#include "../Project II Slider Game/SlidingTilesFunctionsHelpers.hpp"
#include "../Project II Slider Game/UserFunctionsHelpers.hpp"
#include "SlidingTilesFunctionsMock.hpp"


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
			remove("scores_easy.txt");

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);

			Assert::AreEqual((size_t)0, scores.size());
		}

		TEST_METHOD(EmptyFile) {
			std::ofstream out("scores_medium.txt");
			out.close();

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::MEDIUM);

			Assert::AreEqual((size_t)0, scores.size());
		}

		TEST_METHOD(SingleScore) {
			std::ofstream out("scores_easy.txt");
			out << 42 << "\n";
			out.close();

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);

			Assert::AreEqual((size_t)1, scores.size());
			Assert::AreEqual((unsigned int)42, scores[0]);
		}

		TEST_METHOD(MultipleScoresSorted) {
			std::ofstream out("scores_easy.txt");
			out << 50 << "\n" << 20 << "\n" << 30 << "\n";
			out.close();

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);

			Assert::AreEqual((size_t)3, scores.size());
			Assert::AreEqual((unsigned int)20, scores[0]);
			Assert::AreEqual((unsigned int)30, scores[1]);
			Assert::AreEqual((unsigned int)50, scores[2]);
		}

		TEST_METHOD(AlreadySortedInput) {
			std::ofstream out("scores_easy.txt");
			out << 10 << "\n" << 20 << "\n" << 30 << "\n";
			out.close();

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);

			Assert::AreEqual((unsigned int)10, scores[0]);
			Assert::AreEqual((unsigned int)20, scores[1]);
			Assert::AreEqual((unsigned int)30, scores[2]);
		}

		TEST_METHOD(DuplicateScores) {
			std::ofstream out("scores_easy.txt");
			out << 10 << "\n" << 10 << "\n" << 5 << "\n";
			out.close();

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);

			Assert::AreEqual((size_t)3, scores.size());
			Assert::AreEqual((unsigned int)5, scores[0]);
			Assert::AreEqual((unsigned int)10, scores[1]);
			Assert::AreEqual((unsigned int)10, scores[2]);
		}

		TEST_METHOD(ExactlyTop10Scores) {
			std::ofstream out("scores_easy.txt");

			for (int i = 1; i <= 10; i++) {
				out << i << "\n";
			}
			out.close();

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);

			Assert::AreEqual((size_t)10, scores.size());
			Assert::AreEqual((unsigned int)1, scores[0]);
			Assert::AreEqual((unsigned int)10, scores[9]);
		}

		TEST_METHOD(MoreThanTop10Scores) {
			std::ofstream out("scores_easy.txt");

			for (int i = 15; i >= 1; i--) {
				out << i << "\n";
			}
			out.close();

			auto scores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);

			Assert::AreEqual((size_t)SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE, scores.size());

			Assert::AreEqual((unsigned int)1, scores[0]);
			Assert::AreEqual((unsigned int)SlidingTilesFunctionsHelpers::LEADERBOARD_SIZE, scores.back());
		}

		TEST_METHOD(DifferentDifficultyFiles) {
			std::ofstream outEasy("scores_easy.txt");
			outEasy << 5 << "\n";
			outEasy.close();

			std::ofstream outHard("scores_hard.txt");
			outHard << 100 << "\n";
			outHard.close();

			auto easyScores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::EASY);
			auto hardScores = SlidingTilesFunctions::loadScores(SlidingTilesEnums::Difficulty::HARD);

			Assert::AreEqual((unsigned int)5, easyScores[0]);
			Assert::AreEqual((unsigned int)100, hardScores[0]);
		}

	};

}
