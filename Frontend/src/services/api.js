import axios from 'axios';

const API_URL = process.env.REACT_APP_API_BASE_URL || 'http://localhost:8080'; // Replace with your actual backend URL

export const submitPatientInfo = async (patientInfo) => {
    try {
        return await axios.post(`${API_URL}/submitPatientInfo`, patientInfo);
    } catch (error) {
        console.error("There was an error submitting the patient information!", error);
    }
};

export const sendFeedback = async (feedback) => {
    try {
        await axios.post(`${API_URL}/feedback`, { feedback });
    } catch (error) {
        console.error("There was an error sending feedback!", error);
    }
};
