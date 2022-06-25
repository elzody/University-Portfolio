package contact;

import java.util.ArrayList;

// Contact service class
// (Manages the contact list)
public class ContactService {
	// Create an ArrayList of Contact objects that hold all of the existing contacts in memory
	private ArrayList<Contact> contactList = new ArrayList<Contact>();
	
	// A private method that is only used by the ContactService
	// class that determines whether or not a contact with a given
	// ID exists, and returns its index if it exists, otherwise returns -1
	private int find(String id) {
		// Hold the index of the contact, defaults to -1
		int index = -1;
		
		// Loop through the contact list
		for (int i = 0; i < contactList.size(); i++) {
			// If the current contact in the contact list has an ID
			// that matches the ID we are looking for...
			if (contactList.get(i).getID() == id) {
				// Then we set index to the index of the matching contact
				index = i;
				
				// and break out of the loop, because we found our contact
				break;
			}
		}
		
		// Return the index of the found contact to the calling function
		// (or return -1 if the contact doesn't exist yet)
		return index;
	}
	
	// This is a public method that adds a contact to the contact list
	public void add(Contact contact) {
		// If there are more than 0 contacts in the contact list, continue
		if (contactList.size() >= 1) {
			// Hold the index of the contact that matches the ID
			// we are trying to create, or -1 if it doesn't exist yet
			// (Meaning we are good to create a new contact)
			int contactIndex = find(contact.getID());
			
			// If the contact already exists using the specified ID, throw an exception
			if (contactIndex > -1) {
				throw new IllegalArgumentException("Contact ID must be unique: Contact with the given ID already exists");
			} else {
				// If the contact does not yet exist, we are good to add it
				contactList.add(contact);
			}
		} else {
			// If there are no contacts yet, just make one, we don't have to do any checks
			contactList.add(contact);
		}
	}
	
	
	// Public method to remove a contact from the service
	public void remove(String id) {
		// Store the index of the contact that matches the given ID
		// or -1 if it is not found
		int contactIndex = find(id);
		
		// If the contact exists, remove it
		if (contactIndex > -1) {
			contactList.remove(contactIndex);
		} else {
			// If the contact does not exist, throw an exception
			throw new IllegalArgumentException("Contact ID not found: Contact with the given ID cannot be found");
		}
	}
	
	// A public method used to update the contact specified via ID
	public void update(String id, String firstName, String lastName, String phone, String address) {
		// Store the index of the contact that matches the given ID
		// or -1 if it is not found
		int contactIndex = find(id);
		
		// If the contact exists...
		if (contactIndex > -1) {
			// Get the contact and store it in a variable for easy reference
			Contact foundContact = contactList.get(contactIndex);
			
			// If a first name has been provided, update it
			if (firstName != null) {
				foundContact.setFirstName(firstName);
			}
			
			// If a last name has been provided, update it
			if (lastName != null) {
				foundContact.setLastName(lastName);
			}
			
			// If a phone number has been provided, update it
			if (phone != null) {
				foundContact.setPhone(phone);
			}
			
			// If an address has been provided, update it
			if (address != null) {
				foundContact.setAddress(address);
			}
		} else {
			// If the contact does not exist, throw an exception
			throw new IllegalArgumentException("Contact ID not found: Contact with the given ID cannot be found");
		}
	}
}
