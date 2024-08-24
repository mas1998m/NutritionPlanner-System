import React, { useState } from 'react';
import PatientForm from './components/patientForm';
import DietPlan from './components/DietPlan';
import { submitPatientInfo, sendFeedback } from './services/api';
// import './PatientForm.css'; // Import custom styles if needed

// import 'bootstrap/dist/css/bootstrap.min.css';

function App() {
    const [dietPlan, setDietPlan] = useState(null);

    const handleSubmit = async (patientInfo) => {
        const plan = await submitPatientInfo(patientInfo);
        console.log(plan);
        setDietPlan(plan.data);
    };

    const handleFeedback = async (feedback) => {
        await sendFeedback(feedback);
    };

    return (
        <div className="d-flex justify-content-center">
            <div className="container">
                {!dietPlan ? (
                    <PatientForm onSubmit={handleSubmit} />
                ) : (
                    <DietPlan plan={dietPlan} onFeedback={handleFeedback} />
                )}
            </div>
        </div>
    );
}

export default App;
