const mongoose = require('mongoose');

// Define hostname, port, and database name for MongoDB
const host = 'localhost';
const port = '4650';
const db_name = 'travlr';
const user = 'nyx';
const pass = 'siberia';

// Combine them into a Mongo connection URI
const conn_str = `mongodb://${user}:${pass}@${host}:${port}/${db_name}?authSource=admin`;

// Import the seed function to seed our test data
const { seed } = require('./seed');

// Require trips for defining the Mongoose schema
require('./trips');
require('./rooms');
require('./user');

// Set connection and error events for Mongoose
mongoose.connection.on('connected', () => console.log("Connected to DB."));
mongoose.connection.on('error', (err) => console.error(err));
mongoose.connection.on('end', () => console.log("Connected ended."));

// Set strict query
mongoose.set('strictQuery', false);

// Graceful disconnection from MongoDB
async function gracefulDisconnect() {
    await mongoose.connection.close();
}

// Set events for process exit
process.on('SIGINT', () => {
    console.log("Process ended due to keyboard interrupt!");
    
    gracefulDisconnect().then(() => {
        console.log("Database connection ended.");

        process.exit(0);
    })
});

// Define main function which connects to MongoDB via Mongoose
// and seeds our test data into the database
async function main() {
    await mongoose.connect(conn_str);
    await seed();
}

// Execute main and catch any errors
main().catch(err => console.error(err));