package test;

import contact.Contact;
import contact.ContactService;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ContactServiceTest {

	// This test should confirm that an exception is thrown when
	// a contact is added which has a non-unique ID
	// (Adding a contact using an ID that is already linked to another contact)
	@Test
	void testContactServiceAdd() {
		// Create a test contact
		Contact testContact = new Contact("0123456789", "Elizabeth", "Danzberger", "7277277272", "72 Depression Lane");
		
		// Create the contact service instance
		ContactService service = new ContactService();
		
		// Add the test contact to the service
		service.add(testContact);
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Create a new contact with an already existing ID
			Contact newContact = new Contact("0123456789", "Mark", "Ross", "4344344343", "2 I Miss You Street Apt. 9");
			
			// Add the contact with the already existing ID
			service.add(newContact);
		});
	}
	
	// This test should confirm that the service throws an exception when
	// you pass a contact ID that does not exist to the remove() method
	// (Trying to remove a contact that "doesn't exist")
	@Test
	void testContactServiceRemove() {
		// Create a test contact object
		Contact testContact = new Contact("0123456789", "Elizabeth", "Danzberger", "7277277272", "72 Depression Lane");
		
		// Create an instance of the contact service
		ContactService service = new ContactService();
		
		// Add the test contact to the service
		service.add(testContact);
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Try to remove a contact with an invalid/non-existent ID
			service.remove("9876543210");
		});
	}
	
	// This test should confirm that an exception is thrown when
	// an invalid ID is passed to the update() method
	// (A contact that "doesn't exist" is trying to be updated)
	@Test
	void testContactServiceUpdate() {
		// Create a test contact object
		Contact testContact = new Contact("0123456789", "Elizabeth", "Danzberger", "7277277272", "72 Depression Lane");
		
		// Create an instance of the contact service
		ContactService service = new ContactService();
		
		// Add the test contact to the service
		service.add(testContact);
		
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Try to update a contact using an invalid/non-existent ID
			service.update("9876543210", "Elizabeth", "Danzberger", "7277277272", "72 Depression Lane");
		});
	}

}
