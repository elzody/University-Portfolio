

def AllItemsFrequency():
    # We store our items in this Python list
    itemList = []

    # We assume that our input file is in our project directory
    with open("./items_input.txt") as inputFile:
        for line in inputFile:
            # We loop through each line of the file and append each item
            # to our Python list for later use, cutting out the newline character
            # in the process
            itemList.append(line.replace("\n", ''))

    # We loop through the items in our Python list
    for item in itemList:
        # Create a variable to contain the frequency of the item
        count = 0

        # In order to calculate the frequency of each item in this way,
        # I am looping through each item once again and comparing them
        # to the current item
        for i in itemList:
            # If the items are the same (we have encountered a duplicate item)
            # we need to increment the count. We also remove one from the list
            # so that when we display the items only one is shown
            if item == i:
                count = count + 1
                itemList.remove(item)

        # Finally, we print the item and its frequency separated by a dash (-)
        print("{} - {}".format(item, count))


def ItemFrequency(itemName):
    # Create a list to hold our items
    itemList = []

    # We need to store the frequency of the item in this variable
    count = 0

    # We assume that our input file is in our project directory
    with open("./items_input.txt") as inputFile:
        for line in inputFile:
            # We loop through each line of the file and append each item
            # to our Python list for later use, cutting out the newline character
            # in the process
            itemList.append(line.replace("\n", ''))

    # We loop through each item in the list in order to compare
    for item in itemList:
        # If the item is the same as the item given by the user,
        # We have a match, so increment the count
        if item.casefold() == itemName.casefold():
            count = count + 1

    # Return the frequency of the item back to C++ for use there
    return count


def WriteFrequencyFile():
    # We store our items here in this Python list
    itemList = []

    # We assume that our input file is in our project directory
    with open("./items_input.txt") as inputFile:
        for line in inputFile:
            # We loop through each line of the file and append each item
            # to our Python list for later use, cutting out the newline character
            # in the process
            itemList.append(line.replace("\n", ''))

    # If we use the 'with' keyword, it closes the file automatically after use
    with open("./frequency.dat", 'w') as frequencyFile:
        for item in itemList:
            # Keep track of the item frequency in this variable
            count = 0

            # Loop through each item in the list once more for comparison
            for i in itemList:
                if item == i:
                    # If the items are the same, we have duplicates,
                    # which means that we need to increment the item frequency
                    # by one. We also remove one so that when we write it to the file
                    # the item only shows up once along with its frequency
                    count = count + 1
                    itemList.remove(item)

            # Finally, we actually write this data to a file separated by a whitespace
            # and followed by a newline
            frequencyFile.write("{} {}\n".format(item, count))