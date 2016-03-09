#include <stdio.h>
#include "sortedSet.h"

SortedSet::SortedSet()
{
    tree = nullptr;
}

ListPointer *SortedSet::findElement(int value)
{
    return findElement(tree, value);
}

ListPointer *SortedSet::findElement(TreeNode *treeNode, int value)
{
    if (!treeNode)
        return nullptr;
    if (treeNode->listSize == value)
        return treeNode->value;
    if (treeNode->listSize > value)
        return findElement(treeNode->left, value);
    else
        return findElement(treeNode->right, value);
}

void SortedSet::addInSet(ListPointer *value)
{
    addInSet(tree, value);
}

TreeNode *SortedSet::addInSet(TreeNode *&treeNode, ListPointer *value)
{
    if (!treeNode)
    {
        int size = value->length();
        if (!tree)
            return tree = new TreeNode(value, size);
        return new TreeNode(value, size);
    }
    if (compare(treeNode->value, value) > 0)
        treeNode->left = addInSet(treeNode->left, value);
    else
        treeNode->right = addInSet(treeNode->right, value);
    return treeNode = balanceTree(treeNode);
}

void SortedSet::deleteElement(int value)
{
    if (tree)
    {
        deleteElement(tree, value);
    }
}

TreeNode *SortedSet::deleteElement(TreeNode *&treeNode, int value)
{
    if (!treeNode)
        return 0;
    else if (treeNode->listSize > value)
        return deleteElement(treeNode->left, value);
    else if (treeNode->listSize < value)
        return deleteElement(treeNode->right, value);
    else if (treeNode->listSize == value)
    {
        if (treeNode->left == nullptr && treeNode->right == nullptr)
        {
            delete treeNode;
            treeNode = nullptr;
        }
        else if (treeNode->left == nullptr && treeNode->right != nullptr ||
            treeNode->left != nullptr && treeNode->right == nullptr)
        {
            if (treeNode->left)
            {
                TreeNode *temp = treeNode->left;
                delete treeNode;
                treeNode = temp;
            }
            if (treeNode->right)
            {
                TreeNode *temp = treeNode->right;
                delete treeNode;
                treeNode = temp;
            }
            return balanceTree(treeNode);
        }
        else if (treeNode->left != nullptr && treeNode->right != nullptr)
        {
            TreeNode *temp = nullptr;
            treeNode->right = removeElement(treeNode->right, temp);
            TreeNode *left = treeNode->left;
            TreeNode *right = treeNode->right;
            delete treeNode;
            treeNode = temp;
            treeNode->left = left;
            treeNode->right = right;
            return balanceTree(treeNode);
        }
    }
}

TreeNode *SortedSet::removeElement(TreeNode *treeNode, TreeNode *&temp)
{
    if (treeNode->left != nullptr)
    {
        treeNode->left = removeElement(treeNode->left, temp);
    }
    else
    {
        temp = treeNode;
        return treeNode->right;
    }
    return balanceTree(treeNode);
}

int SortedSet::height(TreeNode *treeNode)
{
    if (!treeNode)
        return 0;
    else
        return treeNode->height;
}

int SortedSet::getBalanceFactor(TreeNode *treeNode)
{
    return height(treeNode->right) - height(treeNode->left);
}

void SortedSet::setTheHeight(TreeNode *treeNode)
{
    int heightLeft = height(treeNode->left);
    int heightRight = height(treeNode->right);
    if (heightLeft > heightRight)
        treeNode->height = heightLeft + 1;
    else
        treeNode->height = heightRight + 1;
}

TreeNode *SortedSet::rotateLeft(TreeNode *&treeNode)
{
    TreeNode *temp = treeNode->right;
    treeNode->right = temp->left;
    temp->left = treeNode;
    setTheHeight(treeNode);
    setTheHeight(temp);
    return temp;
}

TreeNode *SortedSet::rotateRight(TreeNode *&treeNode)
{

    TreeNode *temp = treeNode->left;
    treeNode->left = temp->right;
    temp->right = treeNode;
    setTheHeight(treeNode);
    setTheHeight(temp);
    return temp;
}

TreeNode *SortedSet::balanceTree(TreeNode *treeNode)
{
    setTheHeight(treeNode);
    if (getBalanceFactor(treeNode) == 2)
    {
        if (getBalanceFactor(treeNode->right) < 0)
            treeNode->right = rotateRight(treeNode->right);
        return rotateLeft(treeNode);
    }
    if (getBalanceFactor(treeNode) == -2)
    {
        if (getBalanceFactor(treeNode->left) > 0)
            treeNode->left = rotateLeft(treeNode->left);
        return rotateRight(treeNode);
    }
    return treeNode;
}

void SortedSet::printInDescendingOrder()
{
    if (tree)
        printInDescendingOrder(tree);
}

void SortedSet::printInDescendingOrder(TreeNode *treeNode)
{
    if (treeNode->right != nullptr)
        printInDescendingOrder(treeNode->right);
    printf("%d ", treeNode->listSize);
    if (treeNode->left != nullptr)
        printInDescendingOrder(treeNode->left);
}

void SortedSet::printInAscendingOrder()
{
    if (tree)
        printInAscendingOrder(tree);
}

void SortedSet::printInAscendingOrder(TreeNode *treeNode)
{
    if (treeNode->left != nullptr)
        printInAscendingOrder(treeNode->left);
    printf("%d ", treeNode->listSize);
    if (treeNode->right != nullptr)
        printInAscendingOrder(treeNode->right);
}

void SortedSet::debugOutput()
{
    if (tree)
        debugOutput(tree);
}

void SortedSet::debugOutput(TreeNode *treeNode)
{
    printf("(");
    printf("%d ", treeNode->listSize);
    if (treeNode->left != nullptr)
    {
        debugOutput(treeNode->left);
    }
    else
        printf("null ");
    if (treeNode->right != nullptr)
    {
        debugOutput(treeNode->right);
    }
    else
        printf("null");
    printf(")");
}

SortedSet::~SortedSet()
{
    deleteTree(tree);
}

void SortedSet::deleteTree(TreeNode *&treeNode)
{
    if (treeNode)
    {
        if (treeNode->left != nullptr)
            deleteTree(treeNode->left);
        if (treeNode->right != nullptr)
            deleteTree(treeNode->right);
        if (treeNode->left == nullptr && treeNode->right == nullptr)
        {
            delete treeNode;
            treeNode = nullptr;
        }
    }
}
