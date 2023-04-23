import {Component, OnInit, Input, Output, EventEmitter} from '@angular/core';
import { TripsService } from '../services/trips.service';
import { Router } from '@angular/router';
import { Trip } from '../models/trips'

@Component({
  selector: 'app-trip-card',
  templateUrl: './trip-card.component.html',
  styleUrls: ['./trip-card.component.css']
})
export class TripCardComponent implements OnInit {
  @Input('trip') trip: any;
  @Output() deleted: EventEmitter<Trip> = new EventEmitter<Trip>();

  constructor(private tripsService: TripsService, private router: Router) {  };

  ngOnInit(): void {};

  deleteTrip(code: string) {
    this.deleted.next(this.trip);
  }
}
