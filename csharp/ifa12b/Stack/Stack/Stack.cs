using System;

namespace Stack
{
    public class Stack
    {
        private int[] stackArray;
        private int counter;
        private const int maxSize = 8;

        public Stack (int size)
        {
            stackArray = new int[size];
            counter = 0;
        }

        public int getCounter()
        {
            return counter;
        }

        public int pop()
        {
            if (counter > 0)
            {
                counter -= 1;
                return stackArray[counter];
            }
            return 0;
        }

        public bool push(int element)
        {
            if (counter == maxSize)
                return false;

            counter += 1;
            stackArray[counter - 1] = element;
            return true;
        }
    }
}

