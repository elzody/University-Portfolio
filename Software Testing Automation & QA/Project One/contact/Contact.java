package contact;

// Contact class
public class Contact {
	// Private variables for storing id, first name, last name, phone, and address
	private String id;
	private String firstName;
	private String lastName;
	private String phone;
	private String address;
	
	// Class constructor method
	public Contact(String id, String firstName, String lastName, String phone, String address) {
		// If there is not an ID provided or it is greater than 10 characters, throw an exception
		if (id == null || id.length() > 10) {
			throw new IllegalArgumentException("Contact ID is invalid: Must not be null and must not be greater than 10 characters");
		}
		
		// If there is no first name provided, or it is greater than 10 characters, throw an exception
		if (firstName == null || firstName.length() > 10) {
			throw new IllegalArgumentException("Contact first name is invalid: Must not be null and must not be greater than 10 characters");
		}
		
		// If there is no last name provided, or it is greater than 10 characters, throw an exception
		if (lastName == null || lastName.length() > 10) {
			throw new IllegalArgumentException("Contact last name is invalid: Must not be null and must not be greater than 10 characters");
		}
		
		// If there is no phone number provided, or it is not equal to 10 characters exactly, throw an exception
		if (phone == null || phone.length() != 10) {
			throw new IllegalArgumentException("Contact phone is invalid: Must not be null and must be exactly 10 characters");
		}
		
		// If there is no address provided, or it is greater than 30 characters, throw an exception
		if (address == null || address.length() > 30) {
			throw new IllegalArgumentException("Contact address is invalid: Must not be null and must not be greater than 30 characters");
		}
		
		// Otherwise, set them all to their corresponding class properties
		this.id = id;
		this.firstName = firstName;
		this.lastName = lastName;
		this.phone = phone;
		this.address = address;
	}
	
	// Public getter for the ID (no setter)
	public String getID() {
		return this.id;
	}
	
	// Getter for first name
	public String getFirstName() {
		return this.firstName;
	}
	
	// Setter for first name
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	// Getter for last name
	public String getLastName() {
		return this.lastName;
	}
	
	
	// Setter for last name
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	// Getter for phone number
	public String getPhone() {
		return this.phone;
	}
	
	
	// Setter for phone number
	public void setPhone(String phone) {
		this.phone = phone;
	}
	
	
	// Getter for address
	public String getAddress() {
		return this.address;
	}
	
	// Setter for address
	public void setAddress(String address) {
		this.address = address;
	}
}
