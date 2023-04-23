import { Component } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { TripsService } from '../services/trips.service';

@Component({
  selector: 'app-add-trip',
  templateUrl: './add-trip.component.html',
  styleUrls: ['./add-trip.component.css']
})
export class AddTripComponent {
  addForm: FormGroup = this.formBuilder.group({
    _id: [], // leave empty so mongo can auto assign id
    code: [''],
    name: [''],
    length: [''],
    start: [''],
    resort: [''],
    perPerson: [''],
    image: [''],
    description: ['']
  });

  submitted = false;

  constructor(
    private formBuilder: FormBuilder,
    private router: Router,
    private tripsService: TripsService
  ) {  };

  addTrip() {
    this.tripsService.addTrip(this.addForm.value)
      .subscribe({
        next: () => this.router.navigate(['/']),
        error: (e) => console.error(e)
      })
  };

  get f() { return this.addForm.controls };
}
