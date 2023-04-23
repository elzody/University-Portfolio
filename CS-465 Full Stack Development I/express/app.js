require('dotenv').config();

// Global variables
const port = 9821;

// Express imports
const express = require('express');

// Allow cross-origin requests
const cors = require('cors');

// Handlebars templating engine imports
const hbs = require('hbs');

// Node.js imports
const path = require('path');
const fs = require('fs');

// Global pathnames
const app_server_path = path.join(__dirname, 'app_server');
const app_api_path = path.join(__dirname, 'app_api');
const public_path = path.join(app_server_path, 'public');

const routes_path = path.join(app_server_path, 'routes');
const views_path = path.join(app_server_path, 'views');
const models_path = path.join(app_api_path, 'models');

const partials_path = path.join(views_path, 'partials');

// Connect to MongoDB
require(`${models_path}/db`);
require("./app_api/config/passport");

// Routes
const routes = fs.readdirSync('app_server/routes');

// Get an Express application
const app = express();

app.use(express.json()); // this tells express to decode the body of requests as JSON objects

app.use(express.urlencoded({ extended: false }));

// Register Handlebars partials
hbs.registerPartials(partials_path);

/* Set the views engine Express will use
 * as an HTML templating engine to Handlebars*/
app.set('views', views_path);
app.set('view engine', 'hbs');

// Set the homepage
app.use('/', require(`${routes_path}/index`));

// Loop through the routes and attach them to the application
for (let file of routes) {
    if (file.endsWith('.js') && !file.includes('index')) {
        let route = file.substring(0, file.indexOf('.js'));

        app.use(`/${route}`, require(`${routes_path}/${route}`));
    }
}

const api_router = require(`${app_api_path}/routes/index`);

const cors_options = {
    origin: 'http://localhost:4200',
    methods: ['GET', 'POST', 'PUT', 'DELETE'],
    allowedHeaders: ['Content-Type', 'Authorization']
}

app.use('/api', cors(cors_options), api_router);

// Serve resources like stylesheets and images
app.use(express.static(public_path));

// Start the server and listen on the specified port
app.listen(port, () => {
    console.log(`Listening at http://localhost:${port}`);
});