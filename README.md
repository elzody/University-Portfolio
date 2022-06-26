# Portfolio

## Index
1. [CS-210: Programming Languages](#cs-210-programming-languages)
2. [CS-230: Operating Platforms](#cs-230-operating-platforms)
3. [CS-250: Software Development Lifecycle](#cs-250-software-development-lifecycle)
4. [CS-255: System Analysis and Design](#cs-255-system-analysis-and-design)
5. [CS-300: Data Structures and Algorithms](#cs-300-data-structures-and-algorithms)
6. [CS-305: Software Security](#cs-305-software-security)
7. [CS-320: Software Test Automation & QA](#cs-320-software-test-automation--qa)

## CS-210: Programming Languages

The goal of this project was to use Python and C++ side-by-side in order to develop an application that processes a text file of items, calculates the frequency that each item appears, and displays a histogram of the data. It allows you to display the item names and their corresponding frequency, search for a specific item (displaying only that item and its frequency), or display a histogram of all items and their frequencies. Most of this processing happens via Python, but C++ is also an important component in handling the data passed from Python and displaying it to the user.

The most challenging aspect of this project was figuring out the best way to calculate the frequency of each item. I opted to simply loop through the list of items and compare each item until all items have been read. It uses a counter to keep track of the number of times a particular item appears, and then passes that data to C++ for use there.

I think the most important thing that I learned from this project is how to use multiple programming languages in the same project. This is something that I'd never really considered before, but I now realize that this is really important knowledge to have. Each language has unique abilities that may pair well with the abilities of another language. You can use this to your advantage and create some really beautiful code.

## CS-230: Operating Platforms

The Gaming Room is a game studio that needed guidance in how to implement various components of their game, Draw It or Lose it. The game is currently available on Android devices, but they want to expand it to other platforms. The game is to be built from the ground up with portability in mind, as it runs in a user’s web browser and works even on mobile devices. The game needs to host several thousand sessions and users at a time, and host various asset files and other user data.

I think I did particularly well with breaking down the pros and cons of different operating systems when it comes to choosing a server OS. I am knowledgeable on several different operating platforms, and was very thorough in my considerations.

I used to dislike things like software design documents, but after completing this one, I realized how much it helps with development. For example, creating and analyzing a UML Class Diagram was extremely helpful in understand some of the core concepts of object-oriented programming and how it is used in the game. It provides a very nice guideline that you can use when you begin writing code, and helps paint a clearer picture of the structure of the program.

I would likely revise the final section that outlines recommendations. I found it quite difficult to really get into every single recommendation without knowing more about what the client wants specifically, and the other intricate details regarding how they operate and the resources they have available to them. It’s easier when I’m actually involved in the project, rather than looking at it from an outside perspective. Maybe that’s the point of these documents -- to help you get better at this.

The user’s needs are essential, because if they aren’t met, no one is going to want to play the game because it makes for a very poor user experience. It shows that you can pay attention to detail, and that you value your client and your customers’ needs. I interpreted these needs and implemented them into the design document by putting myself in the shoes of client or the users. What would I want from this? I think it’s important to ask yourself, and then compare it with your development lifecycle.

I won’t lie, sometimes I just start writing code and see where it takes me, and then once I have a structure I can write up documents and improve from there. This time, however, the document came first. I approached it very cautiously, because I wanted it to be right. I think it was really helpful to get ideas out onto paper and diagrams before writing code, and I think it’s actually more beneficial. In the future I’d like to keep practicing writing such documents, even if they’re meaningless and will never be used. I sometimes struggle with thinking through the ideas first, which is why I need to practice this more.

## CS-250: Software Development Lifecycle

Interpreting user needs and implementing them into a program is one of the basic skills that one must have when thinking about writing a program. Even if you're just writing it yourself, for yourself, you still need to interpret your thoughts and turn your ideas into concrete information that you can work with. This skill is invaluable, and there are many ways to do this, depending on what works best for you. When interpreting the needs of users who are not yourself, communication is key. You always have to be on the same page with your users. Ask questions, be specific, and ask for clarification when needed. User stories are a really good way to format these things on paper, because it turns these details into concrete information that you can then use to write your program.

When first thinking about developing a program, it typically involves lots of thinking, but also lots of writing code. I tend to think as I work, and adapt as needed based on new information that I discover during the process of writing code. This is, I believe, an agile process in and of itself that I incorporate into my work naturally, and will continue to do so as long as I write code.

The first thing that comes to mind is maturity. Maturity is everything, really. You need to hold yourself accountable, and treat those around you with respect. Use "common sense" and think critically, always. The second thing that is really important is communication. Communication is the key to a lot of things, and can never hurt. Communicate with your team members if you have questions, concerns, or even to offer assistance. The more you communicate, the more you will learn from, teach, and connect with your friends and colleagues.

## CS-255: System Analysis and Design

DriverPass was a client who desired a system that would allow customers to schedule in-person driving lessons with a driving instructor. There were various packages available, each offering an extra perk; these included more driving time with an instructor, online resources, and practice exams. Customers could view their profile, which included notes from their driver, the current progress of their quizes and learning materials, and customer support. Some things that I did particularly well in this project include the creating of the UML diagrams. I created activity diagrams, a class diagram, a use case diagram, and a sequence diagram.

Something that I wish I could revise is the business requirements document. In this document, in the sections regarding limitations and assumptions about the system, I feel as though I could have determined less obvious limitations and assumptions. However, this was somewhat difficult in the context of this project, because it was sort of abstract and I did not have a lot of control as to the low-level aspects of the project.

Considering user needs when designing a product is literally the backbone behind the project. If the project does not address the needs of the user, then what good is it? This is why paying attention to the user’s needs and learning how to interpret them and translate them into something meaningful to the rest of the project team is extremely important. Admittedly, I believe I lack this talent as my interest is programming, but I digress. Still, I recognize the importance of this and without it, writing the code for the project would be like writing code without any direction.

## CS-300: Data Structures and Algorithms

This course involved analyzing various data structures, such as linked lists and binary search trees, in order to determine which data structure is best suited for the problem at hand. It also involved analyzing the runtime and efficiency of various algorithms, such as merge sort and shell sort, in order to determine the best algorithm for the job.

The first project involved writing pseudocode to load data from a csv file into a linked list data structure, a hash table data structure, and a binary search tree data structure. The pseudocode also walks through the steps necessary to implement various search and sorting algorithms for each of these different data structures. Because the csv file contained course data, such as course number, course name, and the prerequisites for the course, I needed to determine which data structure is the best for this type of data. In the end, I chose the binary search tree data structure.

The second and final project involved implementing my chosen data structure (binary search tree) in C++. The program allows the user four choices - parse the course data from the csv file into the binary search tree data structure, display the courses in alphanumerical order, search for a particular course given by a course number, and finally, to exit the program. This project involved implementing a recursive search method that searches the tree for the desired course, if it exists.

Data structures are important to understand because choosing a good data structure can drastically improve the performance of your program. Not only that, but sometimes it makes more sense logically to use a particular data structure versus another.

As a programmer, the internet is one of my closest friends. It aided me in improving my rusty C++ skills throughout this course, and has provided me with many resources to help reinforce the knowledge of data structures and algorithms that I gained from this course. I experienced no significant roadblocks during this course.

My work on these projects has expanded my  approach to designing and developing software because now I pay more attention to the data structures I'm using. I never really bothered to analyze the runtime of algorithms before, although I knew that it was important for them to run efficiently. Learning how to measure the runtime efficiency and space efficiency of algorithms will allow me to develop my own algorithms in the future. My work on these projects has also caused me to be more mindful of the readability of my programs, as the projects in this course were somewhat lengthy and complex. Implementing various algorithms and data structures is no easy task.

## CS-305: Software Security

Artemis Financial is a financial consulting company focused on developing individualized financial plans for savings, retirement, investments, and insurance. Due to the nature of the company, they require modern-day security practices to be implemented into their web application. In this project, I "worked" for a company called Global Rain who was tasked with implementing these security practices and improving the web application in any way possible. I identified security vulnerabilities in the code and the project's dependencies and conducted a vulnerability assessment report for mitigating these vulnerabilities.

The area I think I succeeded in was identifying errors in the code and implementing proper error handling and secure data structures. I also found the areas of cryptography very interesting, as I had to identify a proper cipher suite to be used, implement the SHA-256 hashing algorithm, generate certificates for a secure HTTPS connection, and explain the advantages of using the AES algorithm in cipher block chaining mode. It's important to code securely, because things like lack of exception handling can leak sensitive data if not handled correctly; for example, if an exception is thrown and the program crashes unexpectedly it could leak sensitive financial data. Proper software security implementations can add to a company's overall wellbeing, primarily when it comes to protecting the information of their users, and indeed, their own information when required. They have an obligation to maintain the privacy of their users and implement proper encryption and secure coding practices. It can protect them from attacks, financial loss, and so much more.

When working through the vulnerability assessment, it taught me a lot about how to run dependency checks in Java applications and about OWASP and the National Vulnerability Database. It was really helpful to learn about how to use these tools, because I apply the informataion to other Java applications and any other kind of software. It really taught me to closely analyze code for dependency issues and vulnerabilities, and vulnerabilities intrinsic to various languages, services, and architectures.

Increasing layers of security for this application was guided by the requirements of Artemis Financial and the company's financial nature, as well as the assignment rubric and general programming and software development/design knowledge. For example, the first thing I did was analyze the code manually for any errors and make sure proper secure coding practices were followed. Then, I analyzed the dependencies for vulnerabilities with the help of the dependency check tool, and made sure to supress false-positives and do proper research to determine which vulnerabilities were serious and which were not relevant to the project. I don't think I'd exactly follow this same procedure when working on future projects, as the software security practices implemented need to be tailored specifically to the software being worked on.

To make sure the code was functional and secure after making my additions to the code, I was constantly checking to make sure proper coding practices were being followed and that the code was as efficient as possible. After refactoring the code, I also checked the dependencies again to ensure any new dependencies or code did not contain any known vulnerabilities, and did careful research to mitigate the vulnerabilities if there were any.

I really want to showcase my ability to interpret the needs of the client, Artemis Financial. Interpreting the needs of the client and making sure the software requirements are in order is really the key to developing functional software, and these needs also provide guidance when determining what security practices need to be implemented and where potential vulnerabilities may lie from the outset.

## CS-320: Software Test Automation & QA

A great way to ensure that your software is functional and secure is to conduct unit testing. Writing unit tests for each aspect of your code ensures that your program behaves appropriately in a variety of situations and that your program maintains security throughout execution. These unit tests must be aligned with the software requirements and the "goal" of the program, however; this is perhaps the most important thing to consider.

This leads to interpreting user requirements and incorporating them into the software. It can be really hard to do this, especially for developers. However, it is important to recognize the user requirements and be able to translate them into code. If you fail to interpret the user's needs appropriately, or fail to implement them correctly and efficiently, it could be a huge loss for your company/project. Interpreting the needs of users involves constant communication and listening, and planning. Before writing any code, look at what the user needs and study it. Figure out what these requirements mean, and how they can be applied to software development. Once a set of needs is clearly established, you should begin planning your code. As you program, you should constantly be reviewing the requirements and making sure that you are following them and not getting off track.

This is related to designing software. Designing the software involves a lot of thinking and preparation. Before you write any code, you should plan out your data structures and how you want to accomplish different tasks to satisfy the software requirements. Something that really helps with this is making a UML diagram for each aspect of your software. This is how I break everything down before I begin writing code, and it makes developing the software even easier because you have guidance.