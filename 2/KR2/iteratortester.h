#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "tree.h"

class IteratorTester : public QObject
{
	Q_OBJECT
public:
	explicit IteratorTester(QObject *parent = 0) : QObject(parent) {}

private:
	Tree<int> *tree = new Tree<int>;
	Tree<int>::Iterator *iterator = nullptr;

private slots:

	void initTestCase()
	{
		for (int i = 0; i < 10; i++)
			tree->addInTree(i);
	}

	void cleanupTestCase()
	{
		delete tree;
		delete iterator;
	}

	void init()
	{
		iterator = new Tree<int>::Iterator(tree);
	}

	void cleanup()
	{
		iterator->reset();
	}

	void testNextOnTreeWithOneNode()
	{
		Tree<int> *oneNodeTree = new Tree<int>;
		oneNodeTree->addInTree(1);

		Tree<int>::Iterator *oneNodeIterator = new Tree<int>::Iterator(oneNodeTree);
		oneNodeIterator->remove();
		Tree<int>::TreeNode treeNode = oneNodeIterator->next();
		if(treeNode.getValue())
		{
			QVERIFY2(false, "The function must return zero");
		}
		delete oneNodeIterator;
		delete oneNodeTree;
	}

	void testNextOneTime()
	{
		auto node = iterator->next();
		QVERIFY2(node.getValue() == 3, "Returned the wrong element");
	}

	void testNextAndProceedsToTheNextElement()
	{
		iterator->next();
		auto node = iterator->next();
		QVERIFY2(node.getValue() == 1, "Returned the wrong element");
	}

	void fullByPassOfTree()
	{
		for (int i = 0; i < 10; i++)
		{
			auto node = iterator->next();
			QVERIFY2(iterator->getTree()->isPlaced(node.getValue()), "Returned element which doesn`t place in the tree");
		}
	}

	void fullByPassOfTreeInCorrectOrder()
	{
		QVERIFY2(iterator->next().getValue() == 3, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 1, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 0, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 2, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 7, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 5, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 4, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 6, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 8, "Returned incorrect element");
		QVERIFY2(iterator->next().getValue() == 9, "Returned incorrect element");
	}

	void testIsEmpty()
	{
		QVERIFY2(!iterator->isEmpty(), "Not all elements have been viewed");
		for (int i = 0; i < 25; i++)
			iterator->next();

		QVERIFY2(iterator->isEmpty(), "All elements viewed, but the function return false");
	}

	void testReset()
	{
		auto firstNode = iterator->next();
		for (int i = 0; i < 10; i++)
		{
			iterator->next();
		}
		iterator->reset();

		auto secondNode = iterator->next();
		QVERIFY2(firstNode.getValue() == secondNode.getValue(), "Returned incorret first node");
	}

	void testRemove()
	{
		iterator->remove();
		QVERIFY2(!iterator->getTree()->isPlaced(15), "Element was not deleted");
	}
};
