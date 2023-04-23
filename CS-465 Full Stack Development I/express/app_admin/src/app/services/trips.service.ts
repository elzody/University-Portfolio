import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Trip } from '../models/trips';
import { AuthenticationService } from "./authentication.service";

@Injectable({
  providedIn: 'root'
})
export class TripsService {

  private readonly API_BASE_URL = 'http://localhost:9821/api';

  private token?: string | null;

  constructor(private http: HttpClient, private authService: AuthenticationService) {
    this.authService.tokenSubject.subscribe(t => this.token = t);
  };

  public getTrips(): Observable<Trip[]> {
    return this.http.get<Trip[]>(`${this.API_BASE_URL}/trips`);
  };

  public addTrip(trip: Trip): Observable<Trip> {
    let add_url = `${this.API_BASE_URL}/trips`;

    return this.http.post<Trip>(add_url, trip, {
      headers: new HttpHeaders({
        'Authorization': `Bearer ${this.token}`
      })
    });
  };

  public getTrip(code: string): Observable<Trip> {
    return this.http.get<Trip>(`${this.API_BASE_URL}/trips/${code}`);
  };

  public updateTrip(code: string, trip: Trip): Observable<Trip> {
    let update_url = `${this.API_BASE_URL}/trips/${code}`;

    return this.http.put<Trip>(update_url, trip, {
      headers: new HttpHeaders({
        'Authorization': `Bearer ${this.token}`
      })
    });
  };

  public deleteTrip(code: string): Observable<boolean> {
    let delete_url = `${this.API_BASE_URL}/trips/${code}`;

    return this.http.delete<boolean>(delete_url, {
      headers: new HttpHeaders({
        'Authorization': `Bearer ${this.token}`
      })
    });
  }
}
