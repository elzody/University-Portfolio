import { Component } from '@angular/core';
import { Trip } from '../models/trips';
import { TripsService } from '../services/trips.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-trip-listing',
  templateUrl: './trip-listing.component.html',
  styleUrls: ['./trip-listing.component.css']
})
export class TripListingComponent {
  trips: Trip[] = [];

  constructor(private tripsService: TripsService, private router: Router) {};

  ngOnInit(): void {
    this.tripsService.getTrips()
      .subscribe({
        next: results => this.trips.push(...results),
        error: err => console.error(err)
      });
  };

  addTrip() {
    this.router.navigate(['add-trip']);
  };

  onDelete(trip: Trip) {
    try {
      this.tripsService.deleteTrip(trip.code)
        .subscribe({
          next: () => {
            this.trips = this.trips.filter(t => t.code != trip.code);
          },
          error: e => console.error(e)
        });
    } catch (e) {
      console.error(e);
    }
  }
}
