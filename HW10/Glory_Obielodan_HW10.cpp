//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

class WordNode
{
	public:
		WordNode(int word, int freq = 1, WordNode *left = NULL, WordNode *right = NULL)
		{
			m_Word = word;
			m_frequency = freq;
			pLeftNode = left;
			pRightNode = right;
		}

		int getWord()
		{
			return m_Word;
		}

		void setWord(int word)
		{
			m_Word = word;
		}

		int getFreq()
		{
			return m_frequency;
		}

		void addFreq()
		{
			m_frequency = m_frequency + 1;
		}

		WordNode*& getLeftNode()
		{
			return pLeftNode;
		}

		WordNode*& getRightNode()
		{
			return pRightNode;
		}

		void setLeftNode(WordNode* left)
		{
			pLeftNode = left;
		}

		void setRightNode(WordNode* right)
		{
			pRightNode = right;
		}

	private:
		int m_Word;
		int m_frequency;
		WordNode* pLeftNode;
		WordNode* pRightNode;
};

class WordTree
{
	private:
		WordNode* pRoot;
		int count = 0;

	public:
		WordTree()
		{
			pRoot = NULL;
		}

		int getSize()
		{
			return count;
		}

		void insert_h(int word, WordNode* &node)
		{
			if (node == NULL)
			{
				node = new WordNode(word);
				count++;
			}
			else
			{
				if (word > node->getWord())
				{
					insert_h(word, node->getRightNode());
				}
				else if (word < node->getWord())
				{
					insert_h(word, node->getLeftNode());
				}
				else
				{
					node->addFreq();
				}
			}
		}

		void insert(int word)
		{
			insert_h(word, pRoot);
		}

		void insert_hF(int word, int freq, WordNode* &node)
		{
			if (node == NULL)
			{
				node = new WordNode(word, freq);
				count++;
			}
			else
			{
				if (node->getFreq() > freq)
				{
					insert_hF(word, freq, node->getRightNode());
				}
				else if (node->getFreq() < freq)
				{
					insert_hF(word, freq, node->getLeftNode());
				}
				else if (node->getFreq() == freq)
				{
					if (word > node->getWord())
					{
						insert_hF(word, freq, node->getRightNode());
					}
					else if (word < node->getWord())
					{
						insert_hF(word, freq, node->getLeftNode());
					}
				}
			}
		}

		void insert(int word, int freq)
		{
			insert_hF(word, freq, pRoot);
		}

		void copy_h(WordTree& tree, WordNode* &node)
		{
			if (node != NULL)
			{
				tree.insert(node->getWord(), node->getFreq());
				copy_h(tree, node->getLeftNode());
				copy_h(tree, node->getRightNode());
			}
		}

		void copyTo(WordTree &tree)
		{
			copy_h(tree, pRoot);
		}

		void load(string filename)
		{
			int word;
			ifstream fin;
			fin.open(filename);
			while (!fin.eof())
			{
				fin >> word;
				insert(word);
			}
		}

		void printInorder(ofstream& fout, WordNode* &node)
		{
			if (node == NULL)
			{
				return;
			}
			else
			{
				printInorder(fout, node->getLeftNode());
				fout << node->getWord() << " " << node->getFreq() << endl;
				printInorder(fout, node->getRightNode());
			}
		}

		void save(string filename)
		{
			ofstream fout;
			fout.open(filename);
			printInorder(fout, pRoot);
		}

		int heightTree(WordNode *&node)
		{
			int height = 0;
			if (node) 
			{
				if (node->getLeftNode() || node->getRightNode()) 
				{
					int leftheight = 0, rightheight = 0;
					if (node->getLeftNode()) 
					{
						leftheight = heightTree(node->getLeftNode());
					}
					if (node->getRightNode()) 
					{
						rightheight = heightTree(node->getRightNode());
					}
					if (leftheight > rightheight) 
					{
						height = leftheight + 1;
					}
					else
					{
						height = rightheight + 1;
					}
				}
			}
			return height;
		}

		int getHeight()
		{
			return heightTree(pRoot);
		}
};

int main()
{
	int start_t = clock();
	WordTree treeWord, treeFreq;
	treeWord.load("input.txt");
	treeWord.copyTo(treeFreq);
	treeFreq.save("output.txt");
	int stop_t = clock();
	cout << "Running Time: " << ((stop_t - start_t)/double(CLOCKS_PER_SEC)) << " seconds\n";
	cout << "The size of 'treeWord' is " << treeWord.getSize() << endl;
	cout << "The size of 'treeFreq' is " << treeFreq.getSize() << endl;
	cout << "The height of 'treeWord' is " << treeWord.getHeight() << endl;
	cout << "The height of 'treeFreq' is " << treeFreq.getHeight() << endl;
	return 0;
}