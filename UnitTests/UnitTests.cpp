#include "CppUnitTest.h"

#include "../Project II Slider Game/Board.hpp"
#include "../Project II Slider Game/SlidingTilesData.hpp"
#include "../Project II Slider Game/SlidingTilesFunctions.hpp"
#include "../Project II Slider Game/SlidingTilesEnums.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
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
}
