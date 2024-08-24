import React from 'react';
import usePatientForm from './usePatientForm';

function PatientForm({ onSubmit }) {
    const { formData, handleChange, handleSubmit } = usePatientForm();

    return (
        <div className="container mt-5">
            <h2 className="text-center mb-4">Patient Information Form</h2>
            <form onSubmit={(e) => handleSubmit(e, onSubmit)}>
                <div className="row mb-3">
                    <div className="col-md-6">
                        <label className="form-label">Name:</label>
                        <input
                            type="text"
                            className="form-control"
                            name="name"
                            value={formData.name}
                            onChange={handleChange}
                            required
                        />
                    </div>
                    <div className="col-md-6">
                        <label className="form-label">Age:</label>
                        <input
                            type="number"
                            className="form-control"
                            name="age"
                            value={formData.age}
                            onChange={handleChange}
                            required
                        />
                    </div>
                </div>
                <div className="row mb-3">
                    <div className="col-md-6">
                        <label className="form-label">Gender:</label>
                        <select
                            className="form-select"
                            name="gender"
                            value={formData.gender}
                            onChange={handleChange}
                            required
                        >
                            <option value="" disabled>Select Gender</option>
                            <option value="male">Male</option>
                            <option value="female">Female</option>
                        </select>
                    </div>
                    <div className="col-md-6">
                        <label className="form-label">Height (cm):</label>
                        <input
                            type="text"
                            className="form-control"
                            name="height"
                            value={formData.height}
                            onChange={handleChange}
                            required
                        />
                    </div>
                </div>
                <div className="row mb-3">
                    <div className="col-md-6">
                        <label className="form-label">Weight (kg):</label>
                        <input
                            type="text"
                            className="form-control"
                            name="weight"
                            value={formData.weight}
                            onChange={handleChange}
                            required
                        />
                    </div>
                    <div className="col-md-6">
                        <label className="form-label">Water Intake (liters/day):</label>
                        <input
                            type="text"
                            className="form-control"
                            name="waterIntake"
                            value={formData.waterIntake}
                            onChange={handleChange}
                            required
                        />
                    </div>
                </div>
                <div className="row mb-3">
                    <div className="col-md-6">
                        <label className="form-label">Activity Level:</label>
                        <label className="form-label">Gender:</label>
                        <select
                            className="form-select"
                            name="activityLevel"
                            value={formData.activityLevel}
                            onChange={handleChange}
                            required
                        >
                            <option value="" disabled>Select Activity Level</option>
                            <option value="Sedentary">Sedentary</option>
                            <option value="Lightly Active">Lightly Active</option>
                            <option value="Moderately Active">Moderately Active</option>
                            <option value="Very Active">Very Active</option>
                            <option value="Super Active">Super Active</option>
                        </select>
                    </div>
                    <div className="col-md-6">
                        <label className="form-label">Target Weight (kg):</label>
                        <input
                            type="text"
                            className="form-control"
                            name="targetWeight"
                            value={formData.targetWeight}
                            onChange={handleChange}
                            required
                        />
                    </div>
                </div>
                <div className="row mb-3">
                    <div className="col-12">
                        <label className="form-label">Medical Conditions :</label>
                        <input
                            type="text"
                            className="form-control"
                            name="medicalConditions"
                            value={formData.medicalConditions}
                            onChange={handleChange}
                            required
                        />
                    </div>
                </div>
                <div className="d-grid gap-2">
                    <button type="submit" className="btn btn-primary">Submit</button>
                </div>
            </form>
        </div>
    );
}

export default PatientForm;
