// Require NodeJS modules
const fs = require('fs');
const path = require('path');

// Require Mongoose
const mongoose = require('mongoose');

// Define seed async function
const seed = async () => {
    // Read the parsed JSON data from trips.json
    const trips = JSON.parse(fs.readFileSync(path.join(__dirname, '../../app_server/data/trips.json'), 'utf-8'));
    const rooms = JSON.parse(fs.readFileSync(path.join(__dirname, '../../app_server/data/rooms.json'), 'utf-8'));

    // Create a Mongoose model from the JSON data
    const trip = mongoose.model('trips');
    const room = mongoose.model('rooms');

    // Delete the current documents in the database
    await trip.deleteMany();
    await room.deleteMany();

    // Populate the data from trips.json into the database
    await trip.insertMany(trips);
    await room.insertMany(rooms);
}

// Export the seed function for external use
module.exports = { seed };