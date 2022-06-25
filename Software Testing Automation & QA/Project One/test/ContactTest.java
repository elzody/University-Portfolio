package test;

import contact.Contact;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ContactTest {

	// This test confirms that the contact class can be properly
	// instantiated and that all parameters are not null
	@Test
	void testContactCreate() {
		Contact testContact = new Contact("0123456789", "Elizabeth", "Danzberger", "7277277272", "72 Depression Lane");
		
		assertTrue(testContact.getID().equals("0123456789"));
		assertTrue(testContact.getFirstName().equals("Elizabeth"));
		assertTrue(testContact.getLastName().equals("Danzberger"));
		assertTrue(testContact.getPhone().equals("7277277272"));
		assertTrue(testContact.getAddress().equals("72 Depression Lane"));
	}
	
	// This test will confirm that the ID is within the 10 character limit
	@Test
	void testContactIdTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Create a contact with an invalid ID (over the 10 character limit)
			new Contact("01234567891", "Elizabeth", "Danzberger", "7277277272", "72 Depression Lane");
		});
	}
	
	// This test will confirm that the first name is within the 10 character limit
	@Test
	void testContactFirstNameTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Create a contact with an invalid first name length (greater than 10 character)
			new Contact("0123456789", "Elizabethhh", "Danzberger", "7277277272", "72 Depression Lane");
		});
	}
	
	// This test should confirm that the last name is not too long (within 10 characters)
	@Test
	void testContactLastNameTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Create a contact with an invalid last name parameter (greater than 10 characters)
			new Contact("0123456789", "Elizabeth", "Danzbergerr", "7277277272", "72 Depression Lane");
		});
	}
	
	// This test confirms that an exception is thrown when
	// the phone number is less than or greater than 10 characters
	// (It must be exact)
	@Test
	void testContactPhoneIncorrectLength() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Creates a class with an invalid phone number (too short)
			new Contact("0123456789", "Elizabeth", "Danzberger", "72772", "72 Depression Lane");
		});
	}
	
	
	// This test confirms that an exception is thrown when
	// a contact is being made with an invalid address
	// (greater than 30 characters)
	@Test
	void testContactAddressTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			// Creates a class with an address greater than 30 characters
			new Contact("0123456789", "Elizabeth", "Danzberger", "7277277272", "72 Depression and Anxiety Boulevard");
		});
	}

}
