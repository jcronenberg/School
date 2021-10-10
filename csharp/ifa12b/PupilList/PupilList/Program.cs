using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace PupilList
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int selection = -1;

            // Create anchor for list
            Pupil anchor = null;

            // Testing
            anchor = new Pupil(1, "cba");
            Pupil alloc = new Pupil(2, "acd");
            anchor.next = alloc;
            alloc = new Pupil(3, "abc");
            anchor.next.next = alloc;

            // Menu loop
            do
            {
                printMenu();
                selection = handleSelection();
                switch (selection)
                {
                    // Print List
                    case 1:
                        printList(anchor);
                        break;

                    // Insert new element to end
                    case 2:
                        insertBeforeElement(ref anchor, null);
                        break;

                    // Insert new element before id
                    case 3:
                        Pupil beforeElement = searchForElementById(anchor, askForId());
                        if (beforeElement == null)
                        {
                            Console.WriteLine("Could not find specified id...");
                        }
                        else
                        {
                            insertBeforeElement(ref anchor, beforeElement);
                            Console.WriteLine("Inserted new element!");
                        }
                        break;

                    // delete element
                    case 4:
                        Pupil toDelete = searchForElementById(anchor, askForId());
                        if (toDelete == null)
                        {
                            Console.WriteLine("Could not find specified id...");
                        }
                        else
                        {
                            deleteElement(ref anchor, ref toDelete);

                            Console.WriteLine("Deleted element!");
                        }
                        break;

                    // Delete the whole list
                    case 5:
                        anchor = null;
                        Console.WriteLine("Deleted list!");
                        break;

                    // Sort list by name
                    case 6:
                        sortPupilsByName(ref anchor);
                        break;

                    // Save to file
                    case 7:
                        saveToFile(anchor);
                        break;

                    // Load from file
                    case 8:
                        loadFromFile(ref anchor);
                        break;

                    // Clear screen
                    case 9:
                        Console.Clear();
                        break;

                    // Exit
                    case 0:
                        break;

                    // Temporary
                    default:
                        Console.WriteLine("Not implemented yet");
                        break;
                }


                // Give user a chance to look at the output
                // unless selection was to clear screen
                if (selection != 9)
                {
                    Console.WriteLine("Press enter to continue...");
                    Console.ReadLine();
                }
            } while (selection != 0);
        }

        // Print menu directly to console
        public static void printMenu()
        {
            string menu = String.Join(Environment.NewLine,
                                      "Selection menu for a linked list",
                                      "=================================\n",
                                      "1 = View whole list",
                                      "2 = Insert new element to end of list",
                                      "3 = Insert new element before id ...",
                                      "4 = Delete element",
                                      "5 = Delete the whole list",
                                      "6 = Sort list by name",
                                      "7 = Save list to file",
                                      "8 = Read list from file",
                                      "9 = Clear screen",
                                      "0 = Exit"
            );
            Console.WriteLine(menu);
        }

        // Handle all output and input for the menu selection
        // Returns a valid selection (integer min-max)
        public static int handleSelection(int min = 0, int max = 9)
        {
            int selection = -1;

            while (true) {
                Console.Write("Selection: ");

                // Read selection
                try {
                    selection = Int32.Parse(Console.ReadLine());
                } catch (FormatException) {
                    Console.WriteLine("Error, please input a number...");
                    continue;
                } catch (OverflowException) {
                    Console.WriteLine("Error, input was either too large or too small...");
                    Console.WriteLine($"Allowed range: {Int32.MinValue} - {Int32.MaxValue}");
                    continue;
                }

                // Check for correct input
                if (selection < min || selection > max) {
                    Console.WriteLine($"Invalid selection, only {min}-{max} are valid...\n");
                } else {
                    break;
                }
            }

            return selection;
        }

        // Print the whole List directly to console
        public static void printList(Pupil anchor)
        {
            if (anchor == null) {
                Console.WriteLine("List is empty!");
            }

            while (anchor != null) {
                anchor.printToConsole();

                // Seperator
                Console.WriteLine("");

                anchor = anchor.next;
            }
        }

        // Add a new Pupil to the specified list
        // Element will be inserted before insertBefore element
        // specify null to add element to the end of the list
        // returns new element
        public static Pupil insertBeforeElement(ref Pupil anchor, Pupil insertBefore)
        {
            Pupil alloc = new Pupil();

            if (anchor == null) {
                anchor = alloc;
                return alloc;
            }

            Pupil walk = anchor;

            // walk through list unless first element
            while (walk.next != insertBefore && walk != insertBefore) {
                walk = walk.next;
            }

            // If insertBefore is first element, anchor needs to be changed
            if (anchor != insertBefore) {
                alloc.next = walk.next;
                walk.next = alloc;
            } else {
                alloc.next = walk;
                anchor = alloc;
            }

            return alloc;
        }

        // Search for an element in specified list by id
        // It returns the first element in the list that matches
        // If none match it returns null
        // If list is empty, error message is displayed and null returned
        public static Pupil searchForElementById(Pupil anchor, int id)
        {
            // Check for empty list
            if (anchor == null) {
                Console.WriteLine("Search failed! List is empty...");
                return null;
            }

            while (anchor != null) {
                if (anchor.id == id)
                    break;
                anchor = anchor.next;
            }
            return anchor;
        }

        // Ask user for an id
        // doesn't check if id is valid
        // returns user specified id
        public static int askForId()
        {
            Console.WriteLine($"What's the id of the element?");
            return handleSelection(Int32.MinValue, Int32.MaxValue);
        }

        // delete an element from list
        // if toDelete is null, it just exits
        public static void deleteElement(ref Pupil anchor, ref Pupil toDelete)
        {
            // toDelete is not supposed to be null, so exit if it is
            if (toDelete == null && anchor == null) {
                return;
            // Set anchor to next element if it's supposed to be deleted
            } else if (anchor == toDelete){
                anchor = anchor.next;
                return;
            }

            Pupil walk = anchor;
            while (walk.next != toDelete && walk.next != null) {
                walk = walk.next;
            }

            // delete element, yay garbage collection magic
            if (walk.next != null) {
                walk.next = toDelete.next;
                toDelete = null;
            }
        }

        // Switch position of an element with the element after it in a list
        public static void switchWithNextElement(ref Pupil anchor, Pupil switchElement)
        {
            // if parameters don't allow switching, exit immediately
            if (switchElement == null || anchor == null || switchElement.next == null) {
                return;
            }

            // Special case when anchor == switchElement
            if (anchor == switchElement) {
                anchor = switchElement.next;
                switchElement.next = switchElement.next.next;
                anchor.next = switchElement;
            // Normal case
            } else {
                Pupil walk = anchor;
                while (walk.next != switchElement && switchElement != anchor)
                {
                    walk = walk.next;
                }
                walk.next = switchElement.next;
                switchElement.next = switchElement.next.next;
                walk.next.next = switchElement;
            }
        }

        // Sorts the list in alphabetical order by name of the Pupil
        public static void sortPupilsByName(ref Pupil anchor)
        {
            bool sorted = false;
            while (!sorted) {
                Pupil walk = anchor;
                sorted = true;
                while (walk.next != null) {
                    if (String.Compare(walk.name, walk.next.name) > 0) {
                        switchWithNextElement(ref anchor, walk);
                        sorted = false;
                    } else {
                        walk = walk.next;
                    }
                }
            }
        }

        // Saves the list to the file `pupils` in the current working directory
        // It just overwrites the file if it already exists
        public static void saveToFile(Pupil anchor)
        {
            IFormatter formatter = new BinaryFormatter();
            Stream stream = new FileStream("pupils", FileMode.Create, FileAccess.Write);

            formatter.Serialize(stream, anchor);
            stream.Close();
        }

        // Loades the list from the file `pupils` in the current working directory
        // If the file doesn't exist an error message is displayed and it returns
        public static void loadFromFile(ref Pupil anchor)
        {
            IFormatter formatter = new BinaryFormatter();
            Stream stream;

            try {
                stream = new FileStream("pupils", FileMode.Open, FileAccess.Read);
            } catch (FileNotFoundException) {
                Console.WriteLine("No `pupil` file found in current working directory...");
                return;
            }

            anchor = (Pupil)formatter.Deserialize(stream);

            stream.Close();
        }
    }
}
