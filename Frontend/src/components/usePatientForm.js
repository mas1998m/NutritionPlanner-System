import { useState } from 'react';

const usePatientForm = () => {
    const [formData, setFormData] = useState({
        name: '',
        age: '',
        gender: '',
        height: '',
        weight: '',
        waterIntake: '',
        activityLevel: '',
        targetWeight: '',
        medicalConditions: '',
    });

    const handleChange = (e) => {
        const { name, value } = e.target;
        setFormData({
            ...formData,
            [name]: value
        });
    };

    const handleSubmit = (e, onSubmit) => {
        e.preventDefault();
        onSubmit(formData);
    };

    return {
        formData,
        handleChange,
        handleSubmit
    };
};

export default usePatientForm;